#' Tools To Query WeatherFlow Tempest Weather Station Data
#'
#' The [WeatherFlow](https://weatherflow.com) Tempest Weather System combines
#' state-of-the-art sensors and a sleek, wireless design with WeatherFlow’s proprietary
#' modeling capabilities to seamlessly present validated weather data and improved forecasts.
#' The Tempest API & Developer Platform empowers a growing community of developers to build
#' useful applications and integrations by providing access to enhanced data and forecasts
#' from the Tempest System. Tools are provided to query Tempest Weather station data.
#'
#' @md
#' @name tempestwx
#' @keywords internal
#' @author Bob Rudis (bob@@rud.is)
#' @import httr Rcpp
#' @importFrom jsonlite fromJSON
#' @references
#'   - [Tempest API](https://weatherflow.github.io/Tempest/api/)
#'   - [WeatherFlow](https://weatherflow.com)
#' @useDynLib tempestwx, .registration = TRUE
"_PACKAGE"
