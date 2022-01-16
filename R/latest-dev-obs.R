#' Get latest device observation
#'
#' Get the latest observation from one of your devices.
#'
#' The observations are not named but are in this order:
#'
# - `time_epoch`
# - `wind_lull`
# - `wind_avg`
# - `wind_gust`
# - `wind_direction`
# - `wind_sample_interval`
# - `station_pressure`
# - `air_temperature`
# - `relative_humidity`
# - `luminance`
# - `uv`
# - `solar_radiation`
# - `rain_accumulated`
# - `precipitation_type`
# - `lightning_strike_avg_distance`
# - `lightning_strike_count`
# - `battery_volts`
# - `report_interval`
# - `local_daily_rain_accumulation`
# - `rain_accumulated_final`
# - `local_daily_rain_accumulation_final`
# - `precipitation_analysis_type`
#'
#' @param device_id (chr) device id
#' @param pat see [tempest_pat()]
#' @return list with device metadata, configured, units and point-in-time observation
#' @references <https://weatherflow.github.io/Tempest/api/>
#' @export
#' @examples
#' # latest_device_observation(st$stations$devices[[1]]$device_id[2])$obs
latest_device_observation <- function(device_id, pat = tempest_pat()) {

  httr::GET(
    url = "https://swd.weatherflow.com/swd/rest/observations",
    query = list(
      device_id = device_id[1],
      token = pat[1]
    ),
    .TEMPEST_UA
  ) -> res

  httr::stop_for_status(res)

  out <- httr::content(res, as = "text", encoding = "UTF-8")
  out <- jsonlite::fromJSON(out)

  out

}

