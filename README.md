
[![Project Status: Active – The project has reached a stable, usable
state and is being actively
developed.](https://www.repostatus.org/badges/latest/active.svg)](https://www.repostatus.org/#active)
[![Signed
by](https://img.shields.io/badge/Keybase-Verified-brightgreen.svg)](https://keybase.io/hrbrmstr)
![Signed commit
%](https://img.shields.io/badge/Signed_Commits-100%25-lightgrey.svg)
[![R-CMD-check](https://github.com/hrbrmstr/tempestwx/workflows/R-CMD-check/badge.svg)](https://github.com/hrbrmstr/tempestwx/actions?query=workflow%3AR-CMD-check)
[![Linux build
Status](https://travis-ci.org/hrbrmstr/tempestwx.svg?branch=master)](https://travis-ci.org/hrbrmstr/tempestwx)
[![Coverage
Status](https://codecov.io/gh/hrbrmstr/tempestwx/branch/master/graph/badge.svg)](https://codecov.io/gh/hrbrmstr/tempestwx)
![Minimal R
Version](https://img.shields.io/badge/R%3E%3D-3.6.0-blue.svg)
![License](https://img.shields.io/badge/License-MIT-blue.svg)

# tempestwx

Tools To Query WeatherFlow Tempest Weather Station Data

## Description

The WeatherFlow (<https://weatherflow.com>) Tempest Weather System
combines state-of-the-art sensors and a sleek, wireless design with
WeatherFlow’s proprietary modeling capabilities to seamlessly present
validated weather data and improved forecasts. The Tempest API &
Developer Platform empowers a growing community of developers to build
useful applications and integrations by providing access to enhanced
data and forecasts from the Tempest System. Tools are provided to query
Tempest Weather station data.

## What’s Inside The Tin

The following functions are implemented:

-   `latest_device_observation`: Get latest device observation
-   `latest_observation`: Get latest station observation
-   `tempest_pat`: Get or set TEMPEST_PAT value
-   `tempest_station_meta`: Get station metadata
-   `udp_logger`: Log local UDP Tempest messages to a file

## Installation

``` r
remotes::install_github("hrbrmstr/tempestwx")
```

NOTE: To use the ‘remotes’ install options you will need to have the
[{remotes} package](https://github.com/r-lib/remotes) installed.

## Usage

``` r
library(tempestwx)

# current version
packageVersion("tempestwx")
## [1] '0.1.0'
```

### Station Metadata

``` r
st <- tempest_station_meta()

str(st)
## List of 2
##  $ stations:'data.frame':    1 obs. of  14 variables:
##   ..$ location_id            : int 67915
##   ..$ station_id             : int 67915
##   ..$ name                   : chr "Long Hall Dr"
##   ..$ public_name            : chr "Long Hall Dr"
##   ..$ latitude               : num 43.3
##   ..$ longitude              : num -70.8
##   ..$ timezone               : chr "America/New_York"
##   ..$ timezone_offset_minutes: int -300
##   ..$ station_meta           :'data.frame':  1 obs. of  3 variables:
##   .. ..$ share_with_wf: logi TRUE
##   .. ..$ share_with_wu: logi FALSE
##   .. ..$ elevation    : num 43.1
##   ..$ last_modified_epoch    : int 1642334998
##   ..$ created_epoch          : int 1642272495
##   ..$ devices                :List of 1
##   .. ..$ :'data.frame':  2 obs. of  8 variables:
##   .. .. ..$ device_id        : int [1:2] 184013 184014
##   .. .. ..$ serial_number    : chr [1:2] "HB-00069665" "ST-00054920"
##   .. .. ..$ location_id      : int [1:2] 67915 67915
##   .. .. ..$ device_meta      :'data.frame':  2 obs. of  4 variables:
##   .. .. .. ..$ agl              : num [1:2] 1.83 1.83
##   .. .. .. ..$ name             : chr [1:2] "HB-00069665" "ST-00054920"
##   .. .. .. ..$ environment      : chr [1:2] "indoor" "outdoor"
##   .. .. .. ..$ wifi_network_name: chr [1:2] "" ""
##   .. .. ..$ device_type      : chr [1:2] "HB" "ST"
##   .. .. ..$ hardware_revision: chr [1:2] "1" "1"
##   .. .. ..$ firmware_revision: chr [1:2] "177" "165"
##   .. .. ..$ device_settings  :'data.frame':  2 obs. of  1 variable:
##   .. .. .. ..$ show_precip_final: logi [1:2] NA TRUE
##   ..$ station_items          :List of 1
##   .. ..$ :'data.frame':  6 obs. of  7 variables:
##   .. .. ..$ location_item_id: int [1:6] 557379 557381 557383 557380 557382 557384
##   .. .. ..$ location_id     : int [1:6] 67915 67915 67915 67915 67915 67915
##   .. .. ..$ device_id       : int [1:6] 184014 184014 184014 184014 184014 184014
##   .. .. ..$ item            : chr [1:6] "air_temperature_humidity" "barometric_pressure" "light" "lightning" ...
##   .. .. ..$ sort            : int [1:6] 0 1 5 2 4 3
##   .. .. ..$ station_id      : int [1:6] 67915 67915 67915 67915 67915 67915
##   .. .. ..$ station_item_id : int [1:6] 557379 557381 557383 557380 557382 557384
##   ..$ is_local_mode          : logi FALSE
##  $ status  :List of 2
##   ..$ status_code   : int 0
##   ..$ status_message: chr "SUCCESS"
```

### Latest Observations

``` r
str(
  latest_observation(st$stations$station_id)
)
## List of 12
##  $ station_id   : int 67915
##  $ station_name : chr "Long Hall Dr"
##  $ public_name  : chr "Long Hall Dr"
##  $ latitude     : num 43.3
##  $ longitude    : num -70.8
##  $ timezone     : chr "America/New_York"
##  $ elevation    : num 43.1
##  $ is_public    : logi TRUE
##  $ status       :List of 2
##   ..$ status_code   : int 0
##   ..$ status_message: chr "SUCCESS"
##  $ station_units:List of 7
##   ..$ units_temp     : chr "f"
##   ..$ units_wind     : chr "mph"
##   ..$ units_precip   : chr "in"
##   ..$ units_pressure : chr "inhg"
##   ..$ units_distance : chr "mi"
##   ..$ units_direction: chr "cardinal"
##   ..$ units_other    : chr "imperial"
##  $ outdoor_keys : chr [1:31] "timestamp" "air_temperature" "barometric_pressure" "station_pressure" ...
##  $ obs          :'data.frame':   1 obs. of  31 variables:
##   ..$ timestamp                      : int 1642336517
##   ..$ air_temperature                : num -21.9
##   ..$ barometric_pressure            : num 1025
##   ..$ station_pressure               : num 1025
##   ..$ sea_level_pressure             : num 1031
##   ..$ relative_humidity              : int 89
##   ..$ precip                         : num 0
##   ..$ precip_accum_last_1hr          : num 0
##   ..$ precip_accum_local_day         : num 0
##   ..$ precip_accum_local_day_final   : num 0
##   ..$ precip_accum_local_yesterday   : num 12.1
##   ..$ precip_minutes_local_day       : int 0
##   ..$ precip_minutes_local_yesterday : int 23
##   ..$ wind_avg                       : num 0
##   ..$ wind_direction                 : int 0
##   ..$ wind_gust                      : num 0
##   ..$ wind_lull                      : num 0
##   ..$ solar_radiation                : int 21
##   ..$ uv                             : num 0
##   ..$ brightness                     : int 2577
##   ..$ lightning_strike_count         : int 0
##   ..$ lightning_strike_count_last_1hr: int 0
##   ..$ lightning_strike_count_last_3hr: int 0
##   ..$ feels_like                     : num -21.9
##   ..$ heat_index                     : num -21.9
##   ..$ wind_chill                     : num -21.9
##   ..$ dew_point                      : num -23.2
##   ..$ wet_bulb_temperature           : num -22.1
##   ..$ delta_t                        : num 0.2
##   ..$ air_density                    : num 1.42
##   ..$ pressure_trend                 : chr "rising"
```

### Device Observations

``` r
str(
  latest_device_observation(st$stations$devices[[1]]$device_id[2])$obs
)
##  num [1, 1:22] 1.64e+09 0.00 0.00 0.00 0.00 ...
```

## tempestwx Metrics

| Lang | # Files |  (%) | LoC |  (%) | Blank lines |  (%) | # Lines |  (%) |
|:-----|--------:|-----:|----:|-----:|------------:|-----:|--------:|-----:|
| R    |       8 | 0.31 |  72 | 0.21 |          28 | 0.16 |     107 | 0.33 |
| C++  |       2 | 0.08 |  52 | 0.15 |          26 | 0.15 |      15 | 0.05 |
| YAML |       2 | 0.08 |  35 | 0.10 |          10 | 0.06 |       2 | 0.01 |
| Rmd  |       1 | 0.04 |  16 | 0.05 |          22 | 0.13 |      37 | 0.11 |
| SUM  |      13 | 0.50 | 175 | 0.50 |          86 | 0.50 |     161 | 0.50 |

clock Package Metrics for tempestwx

## Code of Conduct

Please note that this project is released with a Contributor Code of
Conduct. By participating in this project you agree to abide by its
terms.
