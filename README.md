
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
-   `latest_forecast`: Get latest forecast #’
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
##   ..$ last_modified_epoch    : int 1642338598
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
##   ..$ timestamp                      : int 1642341916
##   ..$ air_temperature                : num -13.1
##   ..$ barometric_pressure            : num 1026
##   ..$ station_pressure               : num 1026
##   ..$ sea_level_pressure             : num 1031
##   ..$ relative_humidity              : int 50
##   ..$ precip                         : num 0
##   ..$ precip_accum_last_1hr          : num 0
##   ..$ precip_accum_local_day         : num 0
##   ..$ precip_accum_local_day_final   : num 0
##   ..$ precip_accum_local_yesterday   : num 12.1
##   ..$ precip_minutes_local_day       : int 0
##   ..$ precip_minutes_local_yesterday : int 23
##   ..$ wind_avg                       : num 0.6
##   ..$ wind_direction                 : int 36
##   ..$ wind_gust                      : num 1
##   ..$ wind_lull                      : num 0.2
##   ..$ solar_radiation                : int 253
##   ..$ uv                             : num 1.3
##   ..$ brightness                     : int 30409
##   ..$ lightning_strike_count         : int 0
##   ..$ lightning_strike_count_last_1hr: int 0
##   ..$ lightning_strike_count_last_3hr: int 0
##   ..$ feels_like                     : num -13.1
##   ..$ heat_index                     : num -13.1
##   ..$ wind_chill                     : num -13.1
##   ..$ dew_point                      : num -21.3
##   ..$ wet_bulb_temperature           : num -14.4
##   ..$ delta_t                        : num 1.3
##   ..$ air_density                    : num 1.37
##   ..$ pressure_trend                 : chr "rising"
```

### Device Observations

``` r
str(
  latest_device_observation(st$stations$devices[[1]]$device_id[2])$obs
)
##  num [1, 1:22] 1.64e+09 1.60e-01 6.40e-01 9.60e-01 3.60e+01 ...
```

### Latest Forecast

``` r
knitr::kable(
  latest_forecast(st$stations$station_id[1])$forecast,
  format = "markdown"
)
```

| day_start_local | day_num | month_num | conditions          | icon               |    sunrise |     sunset | air_temp_high | air_temp_low | precip_probability | precip_icon  | precip_type |
|----------------:|--------:|----------:|:--------------------|:-------------------|-----------:|-----------:|--------------:|-------------:|-------------------:|:-------------|:------------|
|      1642309200 |      16 |         1 | Partly Cloudy       | partly-cloudy-day  | 1642335101 | 1642368894 |            -5 |          -20 |                 10 | chance-snow  | snow        |
|      1642395600 |      17 |         1 | Rain Likely         | rainy              | 1642421468 | 1642455368 |             6 |           -7 |                 80 | chance-rain  | rain        |
|      1642482000 |      18 |         1 | Wintry Mix Possible | possibly-sleet-day | 1642507833 | 1642541842 |             1 |          -12 |                 20 | chance-sleet | sleet       |
|      1642568400 |      19 |         1 | Wintry Mix Possible | possibly-sleet-day | 1642594196 | 1642628317 |             2 |          -13 |                 20 | chance-sleet | sleet       |
|      1642654800 |      20 |         1 | Wintry Mix Possible | possibly-sleet-day | 1642680556 | 1642714793 |             1 |          -11 |                 30 | chance-sleet | sleet       |
|      1642741200 |      21 |         1 | Clear               | clear-day          | 1642766915 | 1642801269 |            -8 |          -15 |                 10 | chance-snow  | snow        |
|      1642827600 |      22 |         1 | Snow Possible       | possibly-snow-day  | 1642853271 | 1642887746 |            -7 |          -15 |                 40 | chance-snow  | snow        |
|      1642914000 |      23 |         1 | Snow Possible       | possibly-snow-day  | 1642939625 | 1642974223 |            -2 |           -9 |                 40 | chance-snow  | snow        |
|      1643000400 |      24 |         1 | Snow Possible       | possibly-snow-day  | 1643025977 | 1643060701 |            -4 |          -11 |                 30 | chance-snow  | snow        |
|      1643086800 |      25 |         1 | Snow Possible       | possibly-snow-day  | 1643112327 | 1643147179 |            -6 |          -15 |                 20 | chance-snow  | snow        |

|       time | conditions          | icon                 | air_temperature | sea_level_pressure | relative_humidity | precip | precip_probability | precip_icon  | wind_avg | wind_direction | wind_direction_cardinal | wind_gust |  uv | feels_like | local_hour | local_day | precip_type |
|-----------:|:--------------------|:---------------------|----------------:|-------------------:|------------------:|-------:|-------------------:|:-------------|---------:|---------------:|:------------------------|----------:|----:|-----------:|-----------:|----------:|:------------|
| 1642345200 | Clear               | clear-day            |             -13 |            1030.00 |                49 |   0.00 |                  0 | chance-snow  |        0 |            259 | W                       |         0 |   1 |        -14 |         10 |        16 | NA          |
| 1642348800 | Clear               | clear-day            |             -11 |            1029.40 |                42 |   0.00 |                  0 | chance-snow  |        0 |            251 | WSW                     |         0 |   1 |        -11 |         11 |        16 | NA          |
| 1642352400 | Clear               | clear-day            |              -9 |            1028.10 |                36 |   0.00 |                  0 | chance-snow  |        0 |            235 | SW                      |         0 |   1 |         -9 |         12 |        16 | NA          |
| 1642356000 | Clear               | clear-day            |              -7 |            1027.03 |                28 |   0.00 |                  0 | chance-snow  |        0 |            185 | S                       |         0 |   1 |         -7 |         13 |        16 | NA          |
| 1642359600 | Clear               | clear-day            |              -6 |            1026.59 |                27 |   0.00 |                  0 | chance-snow  |        1 |            181 | S                       |         1 |   1 |         -8 |         14 |        16 | NA          |
| 1642363200 | Clear               | clear-day            |              -5 |            1026.43 |                29 |   0.00 |                  0 | chance-snow  |        2 |            176 | S                       |         2 |   0 |         -8 |         15 |        16 | NA          |
| 1642366800 | Partly Cloudy       | partly-cloudy-day    |              -6 |            1026.18 |                37 |   0.00 |                  0 | chance-snow  |        1 |            161 | SSE                     |         1 |   0 |         -6 |         16 |        16 | NA          |
| 1642370400 | Partly Cloudy       | partly-cloudy-night  |              -8 |            1025.80 |                49 |   0.00 |                  0 | chance-snow  |        0 |            155 | SSE                     |         0 |   0 |         -8 |         17 |        16 | NA          |
| 1642374000 | Partly Cloudy       | partly-cloudy-night  |              -8 |            1025.41 |                56 |   0.00 |                  0 | chance-snow  |        0 |            185 | S                       |         0 |   0 |         -8 |         18 |        16 | NA          |
| 1642377600 | Partly Cloudy       | partly-cloudy-night  |              -9 |            1024.90 |                59 |   0.00 |                  0 | chance-snow  |        3 |            296 | WNW                     |         3 |   0 |        -14 |         19 |        16 | NA          |
| 1642381200 | Partly Cloudy       | partly-cloudy-night  |              -9 |            1024.60 |                63 |   0.00 |                  5 | chance-snow  |        3 |            264 | W                       |         3 |   0 |        -15 |         20 |        16 | snow        |
| 1642384800 | Cloudy              | cloudy               |              -9 |            1023.70 |                66 |   0.00 |                  5 | chance-snow  |        3 |            290 | WNW                     |         3 |   0 |        -15 |         21 |        16 | snow        |
| 1642388400 | Cloudy              | cloudy               |              -9 |            1022.40 |                66 |   0.00 |                  5 | chance-snow  |        4 |              4 | N                       |         5 |   0 |        -15 |         22 |        16 | snow        |
| 1642392000 | Cloudy              | cloudy               |              -8 |            1021.06 |                68 |   0.00 |                  5 | chance-snow  |        4 |             32 | NNE                     |         5 |   0 |        -14 |         23 |        16 | snow        |
| 1642395600 | Cloudy              | cloudy               |              -7 |            1019.61 |                73 |   0.00 |                 10 | chance-snow  |        4 |             53 | NE                      |         5 |   0 |        -13 |          0 |        17 | snow        |
| 1642399200 | Snow Possible       | possibly-snow-night  |              -6 |            1017.71 |                78 |   2.00 |                 35 | chance-snow  |        4 |             56 | NE                      |         8 |   0 |        -12 |          1 |        17 | snow        |
| 1642402800 | Snow Likely         | snow                 |              -4 |            1015.51 |                83 |   3.00 |                 50 | chance-snow  |        5 |             82 | E                       |        10 |   0 |         -9 |          2 |        17 | snow        |
| 1642406400 | Snow Likely         | snow                 |              -1 |            1013.07 |                84 |   5.00 |                 70 | chance-snow  |        6 |             94 | E                       |        12 |   0 |         -7 |          3 |        17 | snow        |
| 1642410000 | Snow Likely         | snow                 |               0 |            1010.31 |                88 |  16.00 |                 80 | chance-snow  |        8 |            102 | ESE                     |        14 |   0 |         -7 |          4 |        17 | snow        |
| 1642413600 | Rain Likely         | rainy                |               0 |            1007.67 |                94 |   2.74 |                 80 | chance-rain  |        9 |            101 | E                       |        15 |   0 |         -6 |          5 |        17 | rain        |
| 1642417200 | Rain Likely         | rainy                |               1 |            1004.87 |                98 |   4.10 |                 80 | chance-rain  |       10 |            101 | E                       |        18 |   0 |         -6 |          6 |        17 | rain        |
| 1642420800 | Rain Likely         | rainy                |               1 |            1001.37 |                98 |   5.46 |                 80 | chance-rain  |       10 |             99 | E                       |        18 |   0 |         -5 |          7 |        17 | rain        |
| 1642424400 | Rain Likely         | rainy                |               2 |             996.97 |                99 |   4.85 |                 80 | chance-rain  |       11 |             94 | E                       |        21 |   0 |         -5 |          8 |        17 | rain        |
| 1642428000 | Rain Likely         | rainy                |               3 |             992.78 |                98 |   5.00 |                 80 | chance-rain  |       12 |             96 | E                       |        23 |   0 |         -3 |          9 |        17 | rain        |
| 1642431600 | Rain Likely         | rainy                |               5 |             988.81 |                94 |   4.22 |                 80 | chance-rain  |       12 |             99 | E                       |        24 |   0 |         -1 |         10 |        17 | rain        |
| 1642435200 | Rain Likely         | rainy                |               6 |             985.46 |                92 |   2.88 |                 80 | chance-rain  |       11 |            120 | ESE                     |        21 |   1 |          1 |         11 |        17 | rain        |
| 1642438800 | Rain Likely         | rainy                |               6 |             983.30 |                90 |   1.11 |                 65 | chance-rain  |        8 |            158 | SSE                     |        15 |   1 |          2 |         12 |        17 | rain        |
| 1642442400 | Rain Possible       | possibly-rainy-day   |               6 |             982.55 |                84 |   0.00 |                 25 | chance-rain  |        7 |            189 | S                       |        14 |   1 |          2 |         13 |        17 | rain        |
| 1642446000 | Cloudy              | cloudy               |               6 |             982.35 |                82 |   0.00 |                 15 | chance-rain  |        7 |            193 | SSW                     |        13 |   1 |          2 |         14 |        17 | rain        |
| 1642449600 | Rain Possible       | possibly-rainy-day   |               5 |             982.35 |                77 |   0.00 |                 20 | chance-rain  |        4 |            197 | SSW                     |         8 |   0 |          2 |         15 |        17 | rain        |
| 1642453200 | Rain Possible       | possibly-rainy-day   |               5 |             982.45 |                78 |   0.00 |                 20 | chance-rain  |        5 |            199 | SSW                     |         9 |   0 |          1 |         16 |        17 | rain        |
| 1642456800 | Cloudy              | cloudy               |               4 |             982.75 |                81 |   0.00 |                 15 | chance-rain  |        4 |            196 | SSW                     |         8 |   0 |          0 |         17 |        17 | rain        |
| 1642460400 | Rain Possible       | possibly-rainy-night |               3 |             983.25 |                82 |   0.00 |                 20 | chance-rain  |        5 |            204 | SSW                     |         9 |   0 |         -1 |         18 |        17 | rain        |
| 1642464000 | Rain Possible       | possibly-rainy-night |               3 |             983.55 |                81 |   0.00 |                 25 | chance-rain  |        4 |            205 | SSW                     |         8 |   0 |         -1 |         19 |        17 | rain        |
| 1642467600 | Rain Possible       | possibly-rainy-night |               3 |             983.69 |                81 |   0.00 |                 20 | chance-rain  |        4 |            206 | SSW                     |         8 |   0 |         -1 |         20 |        17 | rain        |
| 1642471200 | Rain Possible       | possibly-rainy-night |               2 |             983.69 |                83 |   0.00 |                 25 | chance-rain  |        4 |            210 | SSW                     |         8 |   0 |         -2 |         21 |        17 | rain        |
| 1642474800 | Rain Possible       | possibly-rainy-night |               2 |             983.79 |                86 |   0.00 |                 25 | chance-rain  |        4 |            213 | SSW                     |         8 |   0 |         -2 |         22 |        17 | rain        |
| 1642478400 | Wintry Mix Possible | possibly-sleet-night |               1 |             984.14 |                83 |   0.00 |                 20 | chance-sleet |        4 |            228 | SW                      |         7 |   0 |         -3 |         23 |        17 | sleet       |
| 1642482000 | Wintry Mix Possible | possibly-sleet-night |               1 |             984.80 |                77 |   0.00 |                 20 | chance-sleet |        4 |            253 | WSW                     |         8 |   0 |         -4 |          0 |        18 | sleet       |
| 1642485600 | Partly Cloudy       | partly-cloudy-night  |              -1 |             985.84 |                70 |   0.00 |                 10 | chance-snow  |        5 |            271 | W                       |         9 |   0 |         -6 |          1 |        18 | snow        |
| 1642489200 | Partly Cloudy       | partly-cloudy-night  |              -1 |             987.24 |                68 |   0.00 |                  5 | chance-snow  |        5 |            272 | W                       |         9 |   0 |         -7 |          2 |        18 | snow        |
| 1642492800 | Partly Cloudy       | partly-cloudy-night  |              -2 |             988.94 |                63 |   0.00 |                  5 | chance-snow  |        6 |            281 | W                       |        11 |   0 |         -8 |          3 |        18 | snow        |
| 1642496400 | Partly Cloudy       | partly-cloudy-night  |              -3 |             990.64 |                58 |   0.00 |                  0 | chance-snow  |        6 |            286 | WNW                     |        11 |   0 |         -9 |          4 |        18 | NA          |
| 1642500000 | Partly Cloudy       | partly-cloudy-night  |              -4 |             992.54 |                57 |   0.00 |                  0 | chance-snow  |        7 |            289 | WNW                     |        12 |   0 |        -11 |          5 |        18 | NA          |
| 1642503600 | Partly Cloudy       | partly-cloudy-night  |              -5 |             994.40 |                55 |   0.00 |                  0 | chance-snow  |        7 |            288 | WNW                     |        13 |   0 |        -12 |          6 |        18 | NA          |
| 1642507200 | Clear               | clear-night          |              -6 |             996.24 |                55 |   0.00 |                  0 | chance-snow  |        7 |            286 | WNW                     |        12 |   0 |        -13 |          7 |        18 | NA          |
| 1642510800 | Partly Cloudy       | partly-cloudy-day    |              -6 |             998.04 |                54 |   0.00 |                  0 | chance-snow  |        7 |            285 | WNW                     |        13 |   0 |        -14 |          8 |        18 | NA          |
| 1642514400 | Partly Cloudy       | partly-cloudy-day    |              -6 |             999.84 |                52 |   0.00 |                  0 | chance-snow  |        8 |            286 | WNW                     |        14 |   0 |        -14 |          9 |        18 | NA          |
| 1642518000 | Clear               | clear-day            |              -6 |            1001.28 |                50 |   0.00 |                  0 | chance-snow  |        8 |            290 | WNW                     |        15 |   1 |        -14 |         10 |        18 | NA          |
| 1642521600 | Clear               | clear-day            |              -6 |            1002.48 |                47 |   0.00 |                  0 | chance-snow  |        9 |            289 | WNW                     |        15 |   1 |        -14 |         11 |        18 | NA          |
| 1642525200 | Clear               | clear-day            |              -6 |            1003.44 |                43 |   0.00 |                  0 | chance-snow  |        9 |            289 | WNW                     |        15 |   2 |        -14 |         12 |        18 | NA          |
| 1642528800 | Clear               | clear-day            |              -6 |            1004.68 |                40 |   0.00 |                  0 | chance-snow  |        8 |            289 | WNW                     |        15 |   1 |        -14 |         13 |        18 | NA          |
| 1642532400 | Clear               | clear-day            |              -6 |            1006.14 |                38 |   0.00 |                  0 | chance-snow  |        8 |            290 | WNW                     |        15 |   1 |        -14 |         14 |        18 | NA          |
| 1642536000 | Clear               | clear-day            |              -7 |            1007.74 |                38 |   0.00 |                  0 | chance-snow  |        8 |            289 | WNW                     |        14 |   0 |        -15 |         15 |        18 | NA          |
| 1642539600 | Clear               | clear-day            |              -7 |            1009.44 |                37 |   0.00 |                  0 | chance-snow  |        8 |            292 | WNW                     |        14 |   0 |        -15 |         16 |        18 | NA          |
| 1642543200 | Clear               | clear-night          |              -8 |            1011.24 |                38 |   0.00 |                  0 | chance-snow  |        7 |            293 | WNW                     |        12 |   0 |        -16 |         17 |        18 | NA          |
| 1642546800 | Clear               | clear-night          |              -9 |            1013.14 |                38 |   0.00 |                  0 | chance-snow  |        7 |            296 | WNW                     |        12 |   0 |        -17 |         18 |        18 | NA          |
| 1642550400 | Clear               | clear-night          |             -10 |            1014.80 |                38 |   0.00 |                  0 | chance-snow  |        6 |            298 | WNW                     |        11 |   0 |        -18 |         19 |        18 | NA          |
| 1642554000 | Clear               | clear-night          |             -10 |            1016.04 |                41 |   0.00 |                  0 | chance-snow  |        6 |            296 | WNW                     |        10 |   0 |        -18 |         20 |        18 | NA          |
| 1642557600 | Clear               | clear-night          |             -11 |            1017.10 |                43 |   0.00 |                  0 | chance-snow  |        5 |            296 | WNW                     |         9 |   0 |        -19 |         21 |        18 | NA          |
| 1642561200 | Clear               | clear-night          |             -11 |            1018.09 |                45 |   0.00 |                  0 | chance-snow  |        4 |            291 | WNW                     |         8 |   0 |        -18 |         22 |        18 | NA          |
| 1642564800 | Clear               | clear-night          |             -12 |            1019.10 |                46 |   0.00 |                  0 | chance-snow  |        3 |            282 | WNW                     |         3 |   0 |        -18 |         23 |        18 | NA          |
| 1642568400 | Clear               | clear-night          |             -13 |            1020.00 |                48 |   0.00 |                  0 | chance-snow  |        3 |            278 | W                       |         3 |   0 |        -19 |          0 |        19 | NA          |
| 1642572000 | Clear               | clear-night          |             -13 |            1020.64 |                48 |   0.00 |                  0 | chance-snow  |        3 |            278 | W                       |         3 |   0 |        -19 |          1 |        19 | NA          |
| 1642575600 | Partly Cloudy       | partly-cloudy-night  |             -12 |            1021.00 |                48 |   0.00 |                  0 | chance-snow  |        3 |            276 | W                       |         3 |   0 |        -19 |          2 |        19 | NA          |
| 1642579200 | Partly Cloudy       | partly-cloudy-night  |             -12 |            1021.44 |                48 |   0.00 |                  0 | chance-snow  |        3 |            279 | W                       |         3 |   0 |        -18 |          3 |        19 | NA          |
| 1642582800 | Partly Cloudy       | partly-cloudy-night  |             -12 |            1021.80 |                47 |   0.00 |                  0 | chance-snow  |        3 |            279 | W                       |         3 |   0 |        -17 |          4 |        19 | NA          |
| 1642586400 | Partly Cloudy       | partly-cloudy-night  |             -12 |            1022.19 |                47 |   0.00 |                  0 | chance-snow  |        2 |            281 | W                       |         2 |   0 |        -16 |          5 |        19 | NA          |
| 1642590000 | Partly Cloudy       | partly-cloudy-night  |             -12 |            1022.40 |                47 |   0.00 |                  0 | chance-snow  |        1 |            279 | W                       |         1 |   0 |        -12 |          6 |        19 | NA          |
| 1642593600 | Cloudy              | cloudy               |             -11 |            1022.70 |                47 |   0.00 |                  0 | chance-snow  |        1 |            262 | W                       |         1 |   0 |        -11 |          7 |        19 | NA          |
| 1642597200 | Cloudy              | cloudy               |             -10 |            1022.80 |                46 |   0.00 |                  5 | chance-snow  |        1 |            234 | SW                      |         1 |   0 |        -10 |          8 |        19 | snow        |
| 1642600800 | Cloudy              | cloudy               |              -9 |            1022.60 |                46 |   0.00 |                 15 | chance-snow  |        1 |            210 | SSW                     |         1 |   0 |         -9 |          9 |        19 | snow        |
| 1642604400 | Cloudy              | cloudy               |              -7 |            1022.00 |                45 |   0.00 |                 15 | chance-snow  |        2 |            191 | S                       |         2 |   0 |        -10 |         10 |        19 | snow        |
| 1642608000 | Cloudy              | cloudy               |              -6 |            1020.80 |                49 |   0.00 |                 15 | chance-snow  |        2 |            197 | SSW                     |         2 |   1 |         -9 |         11 |        19 | snow        |
| 1642611600 | Cloudy              | cloudy               |              -4 |            1019.10 |                51 |   0.00 |                 15 | chance-snow  |        3 |            189 | S                       |         3 |   1 |         -8 |         12 |        19 | snow        |
| 1642615200 | Cloudy              | cloudy               |              -2 |            1017.40 |                52 |   0.00 |                 15 | chance-snow  |        3 |            186 | S                       |         3 |   1 |         -5 |         13 |        19 | snow        |
| 1642618800 | Cloudy              | cloudy               |               0 |            1014.90 |                56 |   0.00 |                 15 | chance-sleet |        3 |            194 | SSW                     |         3 |   0 |         -4 |         14 |        19 | sleet       |
| 1642622400 | Cloudy              | cloudy               |               1 |            1013.66 |                61 |   0.00 |                 15 | chance-sleet |        3 |            198 | SSW                     |         3 |   0 |         -3 |         15 |        19 | sleet       |
| 1642626000 | Cloudy              | cloudy               |               1 |            1012.80 |                65 |   0.00 |                 15 | chance-sleet |        3 |            205 | SSW                     |         3 |   0 |         -2 |         16 |        19 | sleet       |
| 1642629600 | Cloudy              | cloudy               |               1 |            1012.30 |                70 |   0.00 |                  5 | chance-sleet |        2 |            204 | SSW                     |         2 |   0 |         -2 |         17 |        19 | sleet       |
| 1642633200 | Cloudy              | cloudy               |               1 |            1011.99 |                73 |   0.00 |                  5 | chance-sleet |        3 |            216 | SW                      |         3 |   0 |         -2 |         18 |        19 | sleet       |
| 1642636800 | Cloudy              | cloudy               |               2 |            1011.80 |                73 |   0.00 |                  5 | chance-rain  |        4 |            221 | SW                      |         5 |   0 |         -2 |         19 |        19 | rain        |
| 1642640400 | Cloudy              | cloudy               |               2 |            1011.70 |                77 |   0.00 |                  5 | chance-rain  |        4 |            221 | SW                      |         5 |   0 |         -2 |         20 |        19 | rain        |
| 1642644000 | Cloudy              | cloudy               |               1 |            1011.60 |                79 |   0.00 |                  5 | chance-sleet |        3 |            223 | SW                      |         3 |   0 |         -3 |         21 |        19 | sleet       |
| 1642647600 | Cloudy              | cloudy               |               1 |            1011.55 |                83 |   0.00 |                 10 | chance-sleet |        3 |            223 | SW                      |         3 |   0 |         -3 |         22 |        19 | sleet       |
| 1642651200 | Cloudy              | cloudy               |               0 |            1011.39 |                84 |   0.00 |                 10 | chance-sleet |        3 |            221 | SW                      |         3 |   0 |         -3 |         23 |        19 | sleet       |
| 1642654800 | Cloudy              | cloudy               |               0 |            1011.29 |                86 |   0.00 |                 15 | chance-sleet |        3 |            223 | SW                      |         3 |   0 |         -3 |          0 |        20 | sleet       |
| 1642658400 | Wintry Mix Possible | possibly-sleet-night |               1 |            1011.25 |                83 |   0.00 |                 25 | chance-sleet |        3 |            228 | SW                      |         3 |   0 |         -3 |          1 |        20 | sleet       |
| 1642662000 | Wintry Mix Possible | possibly-sleet-night |               1 |            1011.30 |                83 |   0.00 |                 25 | chance-sleet |        3 |            232 | SW                      |         3 |   0 |         -3 |          2 |        20 | sleet       |
| 1642665600 | Cloudy              | cloudy               |               1 |            1011.44 |                81 |   0.00 |                 15 | chance-sleet |        3 |            237 | WSW                     |         3 |   0 |         -3 |          3 |        20 | sleet       |
| 1642669200 | Wintry Mix Possible | possibly-sleet-night |               1 |            1012.00 |                78 |   0.00 |                 20 | chance-sleet |        3 |            246 | WSW                     |         3 |   0 |         -3 |          4 |        20 | sleet       |
| 1642672800 | Wintry Mix Possible | possibly-sleet-night |               0 |            1012.70 |                73 |   0.00 |                 20 | chance-sleet |        3 |            259 | W                       |         3 |   0 |         -4 |          5 |        20 | sleet       |
| 1642676400 | Snow Possible       | possibly-snow-night  |              -1 |            1013.64 |                67 |   0.00 |                 20 | chance-snow  |        3 |            266 | W                       |         3 |   0 |         -4 |          6 |        20 | snow        |
| 1642680000 | Cloudy              | cloudy               |              -1 |            1014.50 |                67 |   0.00 |                 10 | chance-snow  |        3 |            273 | W                       |         3 |   0 |         -5 |          7 |        20 | snow        |
| 1642683600 | Partly Cloudy       | partly-cloudy-day    |              -2 |            1015.40 |                64 |   0.00 |                 10 | chance-snow  |        4 |            280 | W                       |         5 |   0 |         -6 |          8 |        20 | snow        |
| 1642687200 | Partly Cloudy       | partly-cloudy-day    |              -2 |            1016.30 |                59 |   0.00 |                  5 | chance-snow  |        4 |            286 | WNW                     |         8 |   0 |         -6 |          9 |        20 | snow        |
| 1642690800 | Partly Cloudy       | partly-cloudy-day    |              -1 |            1017.14 |                53 |   0.00 |                  0 | chance-snow  |        4 |            293 | WNW                     |         8 |   1 |         -6 |         10 |        20 | NA          |
| 1642694400 | Partly Cloudy       | partly-cloudy-day    |              -1 |            1017.40 |                47 |   0.00 |                  0 | chance-snow  |        5 |            296 | WNW                     |         9 |   1 |         -6 |         11 |        20 | NA          |
| 1642698000 | Partly Cloudy       | partly-cloudy-day    |              -1 |            1017.40 |                44 |   0.00 |                  0 | chance-snow  |        5 |            297 | WNW                     |         9 |   1 |         -7 |         12 |        20 | NA          |
| 1642701600 | Partly Cloudy       | partly-cloudy-day    |              -2 |            1017.54 |                42 |   0.00 |                  0 | chance-snow  |        4 |            296 | WNW                     |         8 |   1 |         -6 |         13 |        20 | NA          |
| 1642705200 | Partly Cloudy       | partly-cloudy-day    |              -2 |            1018.30 |                42 |   0.00 |                  0 | chance-snow  |        5 |            301 | WNW                     |         8 |   1 |         -7 |         14 |        20 | NA          |
| 1642708800 | Partly Cloudy       | partly-cloudy-day    |              -3 |            1019.20 |                43 |   0.00 |                  0 | chance-snow  |        4 |            306 | NW                      |         8 |   0 |         -8 |         15 |        20 | NA          |
| 1642712400 | Partly Cloudy       | partly-cloudy-day    |              -4 |            1020.15 |                44 |   0.00 |                  0 | chance-snow  |        4 |            313 | NW                      |         8 |   0 |         -9 |         16 |        20 | NA          |
| 1642716000 | Partly Cloudy       | partly-cloudy-night  |              -5 |            1021.40 |                47 |   0.00 |                  0 | chance-snow  |        4 |            314 | NW                      |         7 |   0 |        -11 |         17 |        20 | NA          |
| 1642719600 | Clear               | clear-night          |              -7 |            1022.74 |                48 |   0.00 |                  0 | chance-snow  |        4 |            315 | NW                      |         8 |   0 |        -13 |         18 |        20 | NA          |
| 1642723200 | Clear               | clear-night          |              -8 |            1023.90 |                48 |   0.00 |                  0 | chance-snow  |        4 |            316 | NW                      |         8 |   0 |        -14 |         19 |        20 | NA          |
| 1642726800 | Clear               | clear-night          |              -9 |            1024.84 |                50 |   0.00 |                  0 | chance-snow  |        4 |            318 | NW                      |         5 |   0 |        -15 |         20 |        20 | NA          |
| 1642730400 | Clear               | clear-night          |             -10 |            1025.64 |                50 |   0.00 |                  0 | chance-snow  |        4 |            322 | NW                      |         5 |   0 |        -16 |         21 |        20 | NA          |
| 1642734000 | Clear               | clear-night          |             -11 |            1026.34 |                51 |   0.00 |                  0 | chance-snow  |        3 |            325 | NW                      |         3 |   0 |        -16 |         22 |        20 | NA          |
| 1642737600 | Clear               | clear-night          |             -11 |            1026.94 |                52 |   0.00 |                  0 | chance-snow  |        3 |            322 | NW                      |         3 |   0 |        -17 |         23 |        20 | NA          |
| 1642741200 | Clear               | clear-night          |             -12 |            1027.45 |                52 |   0.00 |                  0 | chance-snow  |        3 |            323 | NW                      |         3 |   0 |        -18 |          0 |        21 | NA          |
| 1642744800 | Clear               | clear-night          |             -13 |            1028.00 |                52 |   0.00 |                  0 | chance-snow  |        3 |            323 | NW                      |         3 |   0 |        -19 |          1 |        21 | NA          |
| 1642748400 | Clear               | clear-night          |             -13 |            1028.54 |                52 |   0.00 |                  0 | chance-snow  |        3 |            324 | NW                      |         3 |   0 |        -19 |          2 |        21 | NA          |
| 1642752000 | Clear               | clear-night          |             -14 |            1029.00 |                53 |   0.00 |                  0 | chance-snow  |        3 |            324 | NW                      |         3 |   0 |        -19 |          3 |        21 | NA          |
| 1642755600 | Clear               | clear-night          |             -14 |            1029.60 |                53 |   0.00 |                  0 | chance-snow  |        2 |            324 | NW                      |         2 |   0 |        -20 |          4 |        21 | NA          |
| 1642759200 | Clear               | clear-night          |             -15 |            1030.20 |                54 |   0.00 |                  0 | chance-snow  |        2 |            328 | NNW                     |         2 |   0 |        -20 |          5 |        21 | NA          |
| 1642762800 | Clear               | clear-night          |             -15 |            1030.95 |                54 |   0.00 |                  0 | chance-snow  |        2 |            332 | NNW                     |         2 |   0 |        -20 |          6 |        21 | NA          |
| 1642766400 | Clear               | clear-night          |             -15 |            1031.65 |                53 |   0.00 |                  0 | chance-snow  |        2 |            329 | NNW                     |         2 |   0 |        -20 |          7 |        21 | NA          |
| 1642770000 | Clear               | clear-day            |             -15 |            1032.25 |                52 |   0.00 |                  0 | chance-snow  |        2 |            332 | NNW                     |         2 |   0 |        -20 |          8 |        21 | NA          |
| 1642773600 | Clear               | clear-day            |             -14 |            1032.80 |                48 |   0.00 |                  0 | chance-snow  |        2 |            333 | NNW                     |         2 |   0 |        -19 |          9 |        21 | NA          |
| 1642777200 | Clear               | clear-day            |             -12 |            1033.14 |                43 |   0.00 |                  0 | chance-snow  |        3 |            339 | NNW                     |         3 |   1 |        -18 |         10 |        21 | NA          |
| 1642780800 | Clear               | clear-day            |             -11 |            1032.90 |                39 |   0.00 |                  0 | chance-snow  |        3 |            334 | NNW                     |         3 |   1 |        -16 |         11 |        21 | NA          |
| 1642784400 | Clear               | clear-day            |             -10 |            1032.20 |                37 |   0.00 |                  0 | chance-snow  |        3 |            333 | NNW                     |         3 |   2 |        -15 |         12 |        21 | NA          |
| 1642788000 | Clear               | clear-day            |              -9 |            1031.70 |                35 |   0.00 |                  0 | chance-snow  |        2 |            333 | NNW                     |         2 |   1 |        -13 |         13 |        21 | NA          |
| 1642791600 | Clear               | clear-day            |              -8 |            1031.70 |                34 |   0.00 |                  0 | chance-snow  |        2 |            332 | NNW                     |         2 |   1 |        -12 |         14 |        21 | NA          |
| 1642795200 | Clear               | clear-day            |              -8 |            1031.70 |                35 |   0.00 |                  0 | chance-snow  |        2 |            336 | NNW                     |         2 |   0 |        -12 |         15 |        21 | NA          |
| 1642798800 | Clear               | clear-day            |              -8 |            1031.90 |                36 |   0.00 |                  0 | chance-snow  |        2 |            342 | NNW                     |         2 |   0 |        -12 |         16 |        21 | NA          |
| 1642802400 | Clear               | clear-night          |              -9 |            1032.30 |                41 |   0.00 |                  0 | chance-snow  |        2 |            345 | NNW                     |         2 |   0 |        -13 |         17 |        21 | NA          |
| 1642806000 | Partly Cloudy       | partly-cloudy-night  |             -10 |            1032.90 |                47 |   0.00 |                  0 | chance-snow  |        2 |            346 | NNW                     |         2 |   0 |        -14 |         18 |        21 | NA          |
| 1642809600 | Partly Cloudy       | partly-cloudy-night  |             -11 |            1033.40 |                49 |   0.00 |                  0 | chance-snow  |        2 |            349 | N                       |         2 |   0 |        -15 |         19 |        21 | NA          |
| 1642813200 | Partly Cloudy       | partly-cloudy-night  |             -12 |            1034.11 |                56 |   0.00 |                  0 | chance-snow  |        2 |            347 | NNW                     |         2 |   0 |        -17 |         20 |        21 | NA          |
| 1642816800 | Partly Cloudy       | partly-cloudy-night  |             -13 |            1034.01 |                58 |   0.00 |                  0 | chance-snow  |        2 |            351 | N                       |         2 |   0 |        -18 |         21 |        21 | NA          |
| 1642820400 | Partly Cloudy       | partly-cloudy-night  |             -13 |            1033.70 |                60 |   0.00 |                  5 | chance-snow  |        2 |            356 | N                       |         2 |   0 |        -18 |         22 |        21 | snow        |
| 1642824000 | Partly Cloudy       | partly-cloudy-night  |             -14 |            1033.10 |                60 |   0.00 |                  5 | chance-snow  |        2 |            354 | N                       |         2 |   0 |        -19 |         23 |        21 | snow        |
| 1642827600 | Partly Cloudy       | partly-cloudy-night  |             -14 |            1032.40 |                63 |   0.00 |                  5 | chance-snow  |        2 |              0 | N                       |         2 |   0 |        -19 |          0 |        22 | snow        |
| 1642831200 | Snow Possible       | possibly-snow-night  |             -14 |            1031.80 |                61 |   0.00 |                 20 | chance-snow  |        3 |            356 | N                       |         3 |   0 |        -20 |          1 |        22 | snow        |
| 1642834800 | Snow Possible       | possibly-snow-night  |             -14 |            1031.35 |                60 |   0.00 |                 20 | chance-snow  |        3 |            356 | N                       |         3 |   0 |        -20 |          2 |        22 | snow        |
| 1642838400 | Snow Possible       | possibly-snow-night  |             -14 |            1030.85 |                59 |   0.00 |                 20 | chance-snow  |        3 |            357 | N                       |         3 |   0 |        -20 |          3 |        22 | snow        |
| 1642842000 | Snow Possible       | possibly-snow-night  |             -14 |            1030.35 |                58 |   0.00 |                 25 | chance-snow  |        3 |            357 | N                       |         3 |   0 |        -20 |          4 |        22 | snow        |
| 1642845600 | Snow Possible       | possibly-snow-night  |             -15 |            1029.85 |                59 |   0.00 |                 25 | chance-snow  |        3 |              1 | N                       |         3 |   0 |        -20 |          5 |        22 | snow        |
| 1642849200 | Snow Possible       | possibly-snow-night  |             -15 |            1029.25 |                59 |   0.00 |                 25 | chance-snow  |        3 |              3 | N                       |         3 |   0 |        -20 |          6 |        22 | snow        |
| 1642852800 | Snow Possible       | possibly-snow-night  |             -15 |            1028.51 |                60 |   0.00 |                 25 | chance-snow  |        3 |            359 | N                       |         3 |   0 |        -20 |          7 |        22 | snow        |
| 1642856400 | Snow Possible       | possibly-snow-day    |             -14 |            1027.56 |                59 |   0.00 |                 25 | chance-snow  |        3 |              0 | N                       |         3 |   0 |        -20 |          8 |        22 | snow        |
| 1642860000 | Snow Possible       | possibly-snow-day    |             -13 |            1026.35 |                55 |   0.00 |                 25 | chance-snow  |        3 |            356 | N                       |         3 |   0 |        -19 |          9 |        22 | snow        |
| 1642863600 | Snow Possible       | possibly-snow-day    |             -12 |            1025.00 |                51 |   0.00 |                 25 | chance-snow  |        3 |            359 | N                       |         3 |   1 |        -18 |         10 |        22 | snow        |
| 1642867200 | Snow Possible       | possibly-snow-day    |             -10 |            1023.31 |                48 |   0.00 |                 25 | chance-snow  |        3 |            355 | N                       |         3 |   1 |        -16 |         11 |        22 | snow        |
| 1642870800 | Snow Possible       | possibly-snow-day    |              -9 |            1021.45 |                46 |   0.00 |                 25 | chance-snow  |        4 |            355 | N                       |         5 |   1 |        -15 |         12 |        22 | snow        |
| 1642874400 | Snow Possible       | possibly-snow-day    |              -8 |            1019.65 |                46 |   7.00 |                 35 | chance-snow  |        3 |            358 | N                       |         3 |   1 |        -13 |         13 |        22 | snow        |
| 1642878000 | Snow Possible       | possibly-snow-day    |              -7 |            1018.06 |                45 |   8.00 |                 35 | chance-snow  |        4 |            354 | N                       |         5 |   1 |        -13 |         14 |        22 | snow        |
| 1642881600 | Snow Possible       | possibly-snow-day    |              -7 |            1016.65 |                47 |  10.00 |                 35 | chance-snow  |        3 |            359 | N                       |         3 |   0 |        -12 |         15 |        22 | snow        |
| 1642885200 | Snow Possible       | possibly-snow-day    |              -7 |            1015.35 |                51 |  12.00 |                 40 | chance-snow  |        4 |              0 | N                       |         5 |   0 |        -13 |         16 |        22 | snow        |
| 1642888800 | Snow Possible       | possibly-snow-night  |              -8 |            1014.46 |                58 |  16.00 |                 40 | chance-snow  |        4 |            359 | N                       |         5 |   0 |        -14 |         17 |        22 | snow        |
| 1642892400 | Snow Possible       | possibly-snow-night  |              -8 |            1013.91 |                64 |  17.00 |                 40 | chance-snow  |        4 |            355 | N                       |         7 |   0 |        -15 |         18 |        22 | snow        |
| 1642896000 | Snow Possible       | possibly-snow-night  |              -9 |            1013.35 |                64 |  12.00 |                 35 | chance-snow  |        4 |            350 | N                       |         7 |   0 |        -15 |         19 |        22 | snow        |
| 1642899600 | Snow Possible       | possibly-snow-night  |              -9 |            1012.80 |                68 |  11.00 |                 35 | chance-snow  |        4 |            344 | NNW                     |         5 |   0 |        -15 |         20 |        22 | snow        |
| 1642903200 | Snow Possible       | possibly-snow-night  |              -9 |            1012.25 |                69 |   9.00 |                 35 | chance-snow  |        3 |            342 | NNW                     |         3 |   0 |        -15 |         21 |        22 | snow        |
| 1642906800 | Snow Possible       | possibly-snow-night  |              -9 |            1011.84 |                68 |   8.00 |                 35 | chance-snow  |        3 |            336 | NNW                     |         3 |   0 |        -14 |         22 |        22 | snow        |
| 1642910400 | Snow Possible       | possibly-snow-night  |              -9 |            1011.60 |                68 |   5.00 |                 35 | chance-snow  |        2 |            325 | NW                      |         2 |   0 |        -13 |         23 |        22 | snow        |
| 1642914000 | Snow Possible       | possibly-snow-night  |              -9 |            1011.44 |                70 |   4.00 |                 35 | chance-snow  |        2 |            333 | NNW                     |         2 |   0 |        -13 |          0 |        23 | snow        |
| 1642917600 | Snow Possible       | possibly-snow-night  |              -9 |            1011.44 |                68 |   0.00 |                 25 | chance-snow  |        2 |            320 | NW                      |         2 |   0 |        -13 |          1 |        23 | snow        |
| 1642921200 | Snow Possible       | possibly-snow-night  |              -9 |            1011.50 |                68 |   0.00 |                 25 | chance-snow  |        2 |            320 | NW                      |         2 |   0 |        -13 |          2 |        23 | snow        |
| 1642924800 | Snow Possible       | possibly-snow-night  |              -9 |            1011.54 |                67 |   0.00 |                 25 | chance-snow  |        2 |            316 | NW                      |         2 |   0 |        -13 |          3 |        23 | snow        |
| 1642928400 | Snow Possible       | possibly-snow-night  |              -9 |            1011.70 |                68 |   0.00 |                 25 | chance-snow  |        2 |            307 | NW                      |         2 |   0 |        -13 |          4 |        23 | snow        |
| 1642932000 | Snow Possible       | possibly-snow-night  |              -9 |            1011.84 |                69 |   0.00 |                 25 | chance-snow  |        2 |            306 | NW                      |         2 |   0 |        -13 |          5 |        23 | snow        |
| 1642935600 | Snow Possible       | possibly-snow-night  |              -9 |            1012.04 |                70 |   0.00 |                 25 | chance-snow  |        2 |            305 | NW                      |         2 |   0 |        -13 |          6 |        23 | snow        |
| 1642939200 | Snow Possible       | possibly-snow-night  |              -9 |            1012.20 |                70 |   0.00 |                 25 | chance-snow  |        2 |            295 | WNW                     |         2 |   0 |        -13 |          7 |        23 | snow        |
| 1642942800 | Snow Possible       | possibly-snow-day    |              -9 |            1012.40 |                69 |   0.00 |                 20 | chance-snow  |        2 |            290 | WNW                     |         2 |   0 |        -13 |          8 |        23 | snow        |
| 1642946400 | Snow Possible       | possibly-snow-day    |              -7 |            1012.60 |                65 |   0.00 |                 20 | chance-snow  |        2 |            289 | WNW                     |         2 |   0 |        -12 |          9 |        23 | snow        |
| 1642950000 | Snow Possible       | possibly-snow-day    |              -6 |            1012.64 |                60 |   0.00 |                 20 | chance-snow  |        3 |            292 | WNW                     |         3 |   1 |        -11 |         10 |        23 | snow        |
| 1642953600 | Snow Possible       | possibly-snow-day    |              -5 |            1012.34 |                55 |   0.00 |                 20 | chance-snow  |        3 |            286 | WNW                     |         3 |   1 |         -9 |         11 |        23 | snow        |
| 1642957200 | Snow Possible       | possibly-snow-day    |              -4 |            1011.80 |                50 |   0.00 |                 20 | chance-snow  |        3 |            278 | W                       |         3 |   2 |         -8 |         12 |        23 | snow        |
| 1642960800 | Partly Cloudy       | partly-cloudy-day    |              -3 |            1011.44 |                49 |   0.00 |                 15 | chance-snow  |        2 |            274 | W                       |         2 |   1 |         -6 |         13 |        23 | snow        |
| 1642964400 | Partly Cloudy       | partly-cloudy-day    |              -2 |            1011.40 |                48 |   0.00 |                 15 | chance-snow  |        3 |            271 | W                       |         3 |   1 |         -6 |         14 |        23 | snow        |
| 1642968000 | Partly Cloudy       | partly-cloudy-day    |              -2 |            1011.40 |                48 |   0.00 |                 15 | chance-snow  |        2 |            267 | W                       |         2 |   0 |         -6 |         15 |        23 | snow        |
| 1642971600 | Partly Cloudy       | partly-cloudy-day    |              -3 |            1011.60 |                50 |   0.00 |                 10 | chance-snow  |        2 |            269 | W                       |         2 |   0 |         -6 |         16 |        23 | snow        |
| 1642975200 | Partly Cloudy       | partly-cloudy-night  |              -4 |            1011.94 |                56 |   0.00 |                 10 | chance-snow  |        2 |            265 | W                       |         2 |   0 |         -7 |         17 |        23 | snow        |
| 1642978800 | Partly Cloudy       | partly-cloudy-night  |              -5 |            1012.40 |                59 |   0.00 |                 15 | chance-snow  |        2 |            271 | W                       |         2 |   0 |         -8 |         18 |        23 | snow        |
| 1642982400 | Partly Cloudy       | partly-cloudy-night  |              -5 |            1012.60 |                61 |   0.00 |                 15 | chance-snow  |        2 |            282 | WNW                     |         2 |   0 |         -9 |         19 |        23 | snow        |
| 1642986000 | Partly Cloudy       | partly-cloudy-night  |              -7 |            1012.60 |                65 |   0.00 |                 15 | chance-snow  |        2 |            277 | W                       |         2 |   0 |        -10 |         20 |        23 | snow        |
| 1642989600 | Partly Cloudy       | partly-cloudy-night  |              -7 |            1012.50 |                68 |   0.00 |                 15 | chance-snow  |        2 |            282 | WNW                     |         2 |   0 |        -11 |         21 |        23 | snow        |
| 1642993200 | Partly Cloudy       | partly-cloudy-night  |              -7 |            1012.40 |                69 |   0.00 |                 15 | chance-snow  |        2 |            283 | WNW                     |         2 |   0 |        -10 |         22 |        23 | snow        |
| 1642996800 | Partly Cloudy       | partly-cloudy-night  |              -7 |            1012.20 |                70 |   0.00 |                 15 | chance-snow  |        2 |            280 | W                       |         2 |   0 |        -11 |         23 |        23 | snow        |
| 1643000400 | Partly Cloudy       | partly-cloudy-night  |              -8 |            1011.94 |                72 |   0.00 |                 15 | chance-snow  |        1 |            283 | WNW                     |         1 |   0 |         -8 |          0 |        24 | snow        |
| 1643004000 | Snow Possible       | possibly-snow-night  |              -8 |            1011.70 |                70 |   0.00 |                 20 | chance-snow  |        2 |            293 | WNW                     |         2 |   0 |        -12 |          1 |        24 | snow        |
| 1643007600 | Snow Possible       | possibly-snow-night  |              -8 |            1011.50 |                71 |   0.00 |                 20 | chance-snow  |        2 |            300 | WNW                     |         2 |   0 |        -12 |          2 |        24 | snow        |
| 1643011200 | Snow Possible       | possibly-snow-night  |              -9 |            1011.35 |                70 |   0.00 |                 20 | chance-snow  |        2 |            301 | WNW                     |         2 |   0 |        -13 |          3 |        24 | snow        |
| 1643014800 | Snow Possible       | possibly-snow-night  |              -9 |            1011.20 |                68 |   0.00 |                 25 | chance-snow  |        2 |            304 | NW                      |         2 |   0 |        -13 |          4 |        24 | snow        |
| 1643018400 | Snow Possible       | possibly-snow-night  |             -10 |            1011.00 |                71 |   0.00 |                 25 | chance-snow  |        2 |            313 | NW                      |         2 |   0 |        -14 |          5 |        24 | snow        |
| 1643022000 | Snow Possible       | possibly-snow-night  |             -10 |            1010.81 |                74 |   0.00 |                 25 | chance-snow  |        3 |            318 | NW                      |         3 |   0 |        -15 |          6 |        24 | snow        |
| 1643025600 | Snow Possible       | possibly-snow-night  |             -10 |            1010.60 |                76 |   6.00 |                 30 | chance-snow  |        3 |            319 | NW                      |         3 |   0 |        -15 |          7 |        24 | snow        |
| 1643029200 | Snow Possible       | possibly-snow-day    |              -9 |            1010.20 |                75 |   8.00 |                 30 | chance-snow  |        3 |            320 | NW                      |         3 |   0 |        -15 |          8 |        24 | snow        |
| 1643032800 | Snow Possible       | possibly-snow-day    |              -8 |            1009.55 |                72 |   0.00 |                 25 | chance-snow  |        3 |            322 | NW                      |         3 |   0 |        -14 |          9 |        24 | snow        |
| 1643036400 | Snow Possible       | possibly-snow-day    |              -7 |            1008.75 |                69 |   0.00 |                 25 | chance-snow  |        4 |            328 | NNW                     |         5 |   1 |        -13 |         10 |        24 | snow        |
| 1643040000 | Snow Possible       | possibly-snow-day    |              -6 |            1007.60 |                65 |   0.00 |                 25 | chance-snow  |        4 |            324 | NW                      |         5 |   1 |        -11 |         11 |        24 | snow        |
| 1643043600 | Snow Possible       | possibly-snow-day    |              -5 |            1006.25 |                62 |   0.00 |                 25 | chance-snow  |        4 |            322 | NW                      |         8 |   2 |        -11 |         12 |        24 | snow        |
| 1643047200 | Snow Possible       | possibly-snow-day    |              -4 |            1005.34 |                60 |   0.00 |                 25 | chance-snow  |        4 |            321 | NW                      |         8 |   1 |        -10 |         13 |        24 | snow        |
| 1643050800 | Snow Possible       | possibly-snow-day    |              -4 |            1004.85 |                59 |   0.00 |                 25 | chance-snow  |        4 |            317 | NW                      |         8 |   1 |         -9 |         14 |        24 | snow        |
| 1643054400 | Snow Possible       | possibly-snow-day    |              -4 |            1004.74 |                60 |   0.00 |                 25 | chance-snow  |        4 |            313 | NW                      |         5 |   0 |         -9 |         15 |        24 | snow        |
| 1643058000 | Snow Possible       | possibly-snow-day    |              -5 |            1004.84 |                63 |   0.00 |                 25 | chance-snow  |        4 |            306 | NW                      |         5 |   0 |        -10 |         16 |        24 | snow        |
| 1643061600 | Snow Possible       | possibly-snow-night  |              -6 |            1005.24 |                67 |   0.00 |                 25 | chance-snow  |        3 |            298 | WNW                     |         3 |   0 |        -11 |         17 |        24 | snow        |
| 1643065200 | Snow Possible       | possibly-snow-night  |              -7 |            1005.74 |                69 |   0.00 |                 25 | chance-snow  |        4 |            292 | WNW                     |         5 |   0 |        -12 |         18 |        24 | snow        |
| 1643068800 | Partly Cloudy       | partly-cloudy-night  |              -8 |            1006.30 |                68 |   0.00 |                 10 | chance-snow  |        4 |            293 | WNW                     |         5 |   0 |        -13 |         19 |        24 | snow        |
| 1643072400 | Partly Cloudy       | partly-cloudy-night  |              -9 |            1006.94 |                66 |   0.00 |                 10 | chance-snow  |        4 |            288 | WNW                     |         5 |   0 |        -15 |         20 |        24 | snow        |
| 1643076000 | Partly Cloudy       | partly-cloudy-night  |             -10 |            1007.54 |                67 |   0.00 |                 10 | chance-snow  |        4 |            288 | WNW                     |         5 |   0 |        -16 |         21 |        24 | snow        |
| 1643079600 | Partly Cloudy       | partly-cloudy-night  |             -10 |            1008.14 |                67 |   0.00 |                  5 | chance-snow  |        3 |            285 | WNW                     |         3 |   0 |        -16 |         22 |        24 | snow        |
| 1643083200 | Partly Cloudy       | partly-cloudy-night  |             -11 |            1008.64 |                68 |   0.00 |                  5 | chance-snow  |        3 |            282 | WNW                     |         3 |   0 |        -17 |         23 |        24 | snow        |
| 1643086800 | Partly Cloudy       | partly-cloudy-night  |             -11 |            1009.20 |                70 |   0.00 |                  5 | chance-snow  |        3 |            280 | W                       |         3 |   0 |        -17 |          0 |        25 | snow        |
| 1643090400 | Partly Cloudy       | partly-cloudy-night  |             -12 |            1009.64 |                70 |   0.00 |                  5 | chance-snow  |        3 |            283 | WNW                     |         3 |   0 |        -18 |          1 |        25 | snow        |
| 1643094000 | Partly Cloudy       | partly-cloudy-night  |             -13 |            1010.20 |                70 |   0.00 |                  5 | chance-snow  |        3 |            285 | WNW                     |         3 |   0 |        -19 |          2 |        25 | snow        |
| 1643097600 | Partly Cloudy       | partly-cloudy-night  |             -14 |            1010.70 |                69 |   0.00 |                  5 | chance-snow  |        3 |            283 | WNW                     |         3 |   0 |        -20 |          3 |        25 | snow        |
| 1643101200 | Partly Cloudy       | partly-cloudy-night  |             -14 |            1011.20 |                68 |   0.00 |                  5 | chance-snow  |        3 |            283 | WNW                     |         3 |   0 |        -21 |          4 |        25 | snow        |
| 1643104800 | Partly Cloudy       | partly-cloudy-night  |             -15 |            1011.74 |                70 |   0.00 |                  5 | chance-snow  |        3 |            285 | WNW                     |         3 |   0 |        -21 |          5 |        25 | snow        |
| 1643108400 | Partly Cloudy       | partly-cloudy-night  |             -15 |            1012.30 |                71 |   0.00 |                  5 | chance-snow  |        3 |            286 | WNW                     |         3 |   0 |        -22 |          6 |        25 | snow        |
| 1643112000 | Partly Cloudy       | partly-cloudy-night  |             -15 |            1012.80 |                72 |   0.00 |                  5 | chance-snow  |        3 |            285 | WNW                     |         3 |   0 |        -22 |          7 |        25 | snow        |
| 1643115600 | Partly Cloudy       | partly-cloudy-day    |             -15 |            1013.20 |                72 |   0.00 |                  5 | chance-snow  |        3 |            283 | WNW                     |         3 |   0 |        -21 |          8 |        25 | snow        |
| 1643119200 | Partly Cloudy       | partly-cloudy-day    |             -13 |            1013.30 |                68 |   0.00 |                  5 | chance-snow  |        3 |            285 | WNW                     |         3 |   0 |        -20 |          9 |        25 | snow        |
| 1643122800 | Partly Cloudy       | partly-cloudy-day    |             -11 |            1013.20 |                63 |   0.00 |                  5 | chance-snow  |        4 |            286 | WNW                     |         5 |   1 |        -17 |         10 |        25 | snow        |
| 1643126400 | Partly Cloudy       | partly-cloudy-day    |              -9 |            1012.99 |                58 |   0.00 |                  5 | chance-snow  |        3 |            283 | WNW                     |         3 |   1 |        -15 |         11 |        25 | snow        |
| 1643130000 | Partly Cloudy       | partly-cloudy-day    |              -8 |            1012.69 |                54 |   0.00 |                  5 | chance-snow  |        3 |            278 | W                       |         3 |   2 |        -13 |         12 |        25 | snow        |
| 1643133600 | Partly Cloudy       | partly-cloudy-day    |              -7 |            1012.60 |                52 |   0.00 |                  5 | chance-snow  |        3 |            278 | W                       |         3 |   1 |        -11 |         13 |        25 | snow        |
| 1643137200 | Partly Cloudy       | partly-cloudy-day    |              -6 |            1012.90 |                53 |   0.00 |                  5 | chance-snow  |        3 |            275 | W                       |         3 |   1 |        -11 |         14 |        25 | snow        |
| 1643140800 | Partly Cloudy       | partly-cloudy-day    |              -6 |            1013.20 |                53 |   0.00 |                  5 | chance-snow  |        3 |            274 | W                       |         3 |   0 |        -10 |         15 |        25 | snow        |
| 1643144400 | Partly Cloudy       | partly-cloudy-day    |              -6 |            1013.50 |                56 |   0.00 |                 15 | chance-snow  |        3 |            276 | W                       |         3 |   0 |        -11 |         16 |        25 | snow        |
| 1643148000 | Partly Cloudy       | partly-cloudy-night  |              -7 |            1013.80 |                60 |   0.00 |                 15 | chance-snow  |        3 |            270 | W                       |         3 |   0 |        -11 |         17 |        25 | snow        |
| 1643151600 | Partly Cloudy       | partly-cloudy-night  |              -7 |            1014.20 |                61 |   0.00 |                 15 | chance-snow  |        3 |            273 | W                       |         3 |   0 |        -11 |         18 |        25 | snow        |
| 1643155200 | Partly Cloudy       | partly-cloudy-night  |              -7 |            1014.50 |                62 |   0.00 |                  5 | chance-snow  |        3 |            278 | W                       |         3 |   0 |        -12 |         19 |        25 | snow        |
| 1643158800 | Partly Cloudy       | partly-cloudy-night  |              -9 |            1014.00 |                64 |   0.00 |                  5 | chance-snow  |        3 |            280 | W                       |         3 |   0 |        -14 |         20 |        25 | snow        |
| 1643162400 | Partly Cloudy       | partly-cloudy-night  |              -9 |            1014.60 |                65 |   0.00 |                  5 | chance-snow  |        3 |            282 | WNW                     |         3 |   0 |        -15 |         21 |        25 | snow        |
| 1643166000 | Partly Cloudy       | partly-cloudy-night  |             -10 |            1015.04 |                69 |   0.00 |                  5 | chance-snow  |        3 |            278 | W                       |         3 |   0 |        -15 |         22 |        25 | snow        |
| 1643169600 | Partly Cloudy       | partly-cloudy-night  |             -10 |            1015.50 |                69 |   0.00 |                  5 | chance-snow  |        3 |            276 | W                       |         3 |   0 |        -15 |         23 |        25 | snow        |
| 1643173200 | Partly Cloudy       | partly-cloudy-night  |             -10 |            1015.94 |                73 |   0.00 |                  5 | chance-snow  |        2 |            273 | W                       |         2 |   0 |        -14 |          0 |        26 | snow        |
| 1643176800 | Snow Possible       | possibly-snow-night  |             -11 |            1016.34 |                72 |   0.00 |                 20 | chance-snow  |        2 |            279 | W                       |         2 |   0 |        -15 |          1 |        26 | snow        |
| 1643180400 | Snow Possible       | possibly-snow-night  |             -11 |            1016.74 |                71 |   0.00 |                 20 | chance-snow  |        2 |            285 | WNW                     |         2 |   0 |        -15 |          2 |        26 | snow        |
| 1643184000 | Snow Possible       | possibly-snow-night  |             -11 |            1017.20 |                72 |   0.00 |                 20 | chance-snow  |        3 |            281 | W                       |         3 |   0 |        -16 |          3 |        26 | snow        |
| 1643187600 | Snow Possible       | possibly-snow-night  |             -11 |            1017.64 |                71 |   0.00 |                 20 | chance-snow  |        2 |            282 | WNW                     |         2 |   0 |        -16 |          4 |        26 | snow        |
| 1643191200 | Snow Possible       | possibly-snow-night  |             -12 |            1018.14 |                73 |   0.00 |                 20 | chance-snow  |        2 |            287 | WNW                     |         2 |   0 |        -17 |          5 |        26 | snow        |
| 1643194800 | Snow Possible       | possibly-snow-night  |             -12 |            1018.64 |                73 |   0.00 |                 20 | chance-snow  |        2 |            293 | WNW                     |         2 |   0 |        -17 |          6 |        26 | snow        |
| 1643198400 | Snow Possible       | possibly-snow-night  |             -12 |            1019.10 |                73 |   0.00 |                 20 | chance-snow  |        2 |            293 | WNW                     |         2 |   0 |        -17 |          7 |        26 | snow        |
| 1643202000 | Snow Possible       | possibly-snow-day    |             -11 |            1019.40 |                73 |   0.00 |                 20 | chance-snow  |        2 |            291 | WNW                     |         2 |   0 |        -16 |          8 |        26 | snow        |
| 1643205600 | Partly Cloudy       | partly-cloudy-day    |             -10 |            1019.54 |                70 |   0.00 |                 15 | chance-snow  |        3 |            295 | WNW                     |         3 |   1 |        -15 |          9 |        26 | snow        |
| 1643209200 | Partly Cloudy       | partly-cloudy-day    |              -9 |            1019.50 |                66 |   0.00 |                 15 | chance-snow  |        3 |            297 | WNW                     |         3 |   1 |        -14 |         10 |        26 | snow        |

## tempestwx Metrics

| Lang | # Files |  (%) | LoC |  (%) | Blank lines |  (%) | # Lines |  (%) |
|:-----|--------:|-----:|----:|-----:|------------:|-----:|--------:|-----:|
| R    |       9 | 0.32 |  86 | 0.22 |          33 | 0.17 |     118 | 0.34 |
| C++  |       2 | 0.07 |  54 | 0.14 |          28 | 0.15 |      15 | 0.04 |
| YAML |       2 | 0.07 |  35 | 0.09 |          10 | 0.05 |       2 | 0.01 |
| Rmd  |       1 | 0.04 |  20 | 0.05 |          24 | 0.13 |      40 | 0.11 |
| SUM  |      14 | 0.50 | 195 | 0.50 |          95 | 0.50 |     175 | 0.50 |

clock Package Metrics for tempestwx

## Code of Conduct

Please note that this project is released with a Contributor Code of
Conduct. By participating in this project you agree to abide by its
terms.
