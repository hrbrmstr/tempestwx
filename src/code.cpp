#include <Rcpp.h>

using namespace Rcpp;

#include <iostream>
#include <fstream>
#include <netinet/in.h>
#include <functional>
#include <string.h>

//' Log local UDP Tempest messages to a file
//'
//' This dedicates the R session to logging UDP packets to a file. No other operations
//' can be performed until terminated.
//'
//' @param path full path (no expansion is performed) to a file
//' @references <https://weatherflow.github.io/Tempest/api/>
//' @return nothing
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

  setsockopt(s, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof broadcast);

  memset(&si_me, 0, sizeof(si_me));

  si_me.sin_family = AF_INET;
  si_me.sin_port = htons(port);
  si_me.sin_addr.s_addr = INADDR_ANY;

  ::bind(s, (sockaddr *)&si_me, sizeof(sockaddr));

  while(true) {

    char buf[10*1024];
    unsigned slen = sizeof(sockaddr);

    recvfrom(s, buf, sizeof(buf)-1, 0, (sockaddr *)&si_other, &slen);

    file_stream << buf << std::endl;

    Rcpp::checkUserInterrupt();

  }

  file_stream.close();

}
