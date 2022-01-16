#' Get station metadata
#'
#' Retrieve a list of your stations along with all connected devices.
#'
#' @param pat see [tempest_pat()]
#' @return list with station metadata
#' @references <https://weatherflow.github.io/Tempest/api/>
#' @export
#' @examples
#' # tempest_station_meta()
tempest_station_meta <- function(pat = tempest_pat()) {

  httr::GET(
    url = "https://swd.weatherflow.com/swd/rest/stations",
    query = list(
      token = pat[1]
    ),
    .TEMPEST_UA
  ) -> res

  httr::stop_for_status(res)

  out <- httr::content(res, as = "text", encoding = "UTF-8")
  out <- jsonlite::fromJSON(out)

  out

}