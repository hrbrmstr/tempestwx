#' Get latest forecast
#'#'
#' @param station_id (chr) station id
#' @param pat see [tempest_pat()]
#' @return list with station metadata, configured, units and forecast information
#' @export
#' @references [Tempest API](https://weatherflow.github.io/Tempest/api/)
#' @examples \dontrun{
#' st <- tempest_station_meta()
#' latest_observation(st$stations$station_id)
#' }
latest_forecast <- function(station_id, pat = tempest_pat()) {

  httr::GET(
    url = "https://swd.weatherflow.com/swd/rest/better_forecast",
    query = list(
      station_id = station_id[1],
      token = pat[1]
    ),
    .TEMPEST_UA
  ) -> res

  httr::stop_for_status(res)

  out <- httr::content(res, as = "text", encoding = "UTF-8")
  out <- jsonlite::fromJSON(out)

  out

}