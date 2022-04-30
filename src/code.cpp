#include <Rcpp.h>

using namespace Rcpp;

#include <iostream>
#include <fstream>
#include <netinet/in.h>
#include <unistd.h>
#include <functional>
#include <string.h>

#define BUF_LEN 1024

/* Check for interrupt without long jumping */
void check_interrupt_fn(void *dummy) {
  R_CheckUserInterrupt();
}

int pending_interrupt() {
  return !(R_ToplevelExec(check_interrupt_fn, NULL));
}

//' Log local UDP Tempest messages to a file
//'
//' This dedicates the R session to logging UDP packets to a file. No other operations
//' can be performed until terminated.
//'
//' @param path full path (no expansion is performed) to a file
//' @references <https://weatherflow.github.io/Tempest/api/udp/v171/>
//' @return nothing!
//' @export
//' @examples
//' # udp_logger("/tmp/logger.json")
// [[Rcpp::export]]
void udp_logger(std::string path) {

  std::ofstream file_stream;

  file_stream.open(path);

  struct sockaddr_in si_me, si_other;

  int s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

  int port = 50222;
  int broadcast = 1;
  int reuse_port = 1;
  int reuse_address = 1;

  bool processing = true;

  setsockopt(s, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof broadcast);
  setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &reuse_address, sizeof(reuse_address));
#ifdef __APPLE__
  setsockopt(s, SOL_SOCKET, SO_REUSEPORT, &reuse_port, sizeof(reuse_port));
#endif

  memset(&si_me, 0, sizeof(si_me));

  si_me.sin_family = AF_INET;
  si_me.sin_port = htons(port);
  si_me.sin_addr.s_addr = INADDR_ANY;

  ::bind(s, (sockaddr *)&si_me, sizeof(sockaddr));

  while(processing) {

    char buf[BUF_LEN];
    unsigned slen = sizeof(sockaddr);

    int n = recvfrom(s, buf, sizeof(buf)-1, 0, (sockaddr *)&si_other, &slen);

    file_stream << std::string(buf, 0, n) << std::endl;

    if (pending_interrupt()) {
      processing = false;
    }

  }

  file_stream.close();

   close(s);

}

//' Log local UDP Tempest messages to a file
//'
//' This dedicates the R session to logging UDP packets to a file. No other operations
//' can be performed until terminated.
//'
//' @param f R function callback (one param: length 1 chr)
//' @references <https://weatherflow.github.io/Tempest/api/udp/v171/>
//' @return nothing!
//' @export
//' @examples
//' # udp_callback_logger(function(x) writeLines(x))
// [[Rcpp::export]]
void udp_callback_logger(Function f) {

  struct sockaddr_in si_me, si_other;

  int s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

  int port = 50222;
  int broadcast = 1;
  int reuse_port = 1;
  int reuse_address = 1;

  bool processing = true;

  setsockopt(s, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof broadcast);
  setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &reuse_address, sizeof(reuse_address));
#ifdef __APPLE__
  setsockopt(s, SOL_SOCKET, SO_REUSEPORT, &reuse_port, sizeof(reuse_port));
#endif

  memset(&si_me, 0, sizeof(si_me));

  si_me.sin_family = AF_INET;
  si_me.sin_port = htons(port);
  si_me.sin_addr.s_addr = INADDR_ANY;

  ::bind(s, (sockaddr *)&si_me, sizeof(sockaddr));

  while(processing) {

    char buf[BUF_LEN];
    unsigned slen = sizeof(sockaddr);

    int n = recvfrom(s, buf, sizeof(buf)-1, 0, (sockaddr *)&si_other, &slen);

    LogicalVector res = f(CharacterVector(std::string(buf, 0, n)));

    if ((is_true(all(res))) || pending_interrupt()) {
      processing = false;
    }

  }

  close(s);

}
