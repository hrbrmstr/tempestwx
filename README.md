
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

Tools To Query Tempest Weather Station Data

## Description

The Tempest Weather System combines state-of-the-art sensors and a
sleek, wireless design with WeatherFlow’s proprietary modeling
capabilities to seamlessly present validated weather data and improved
forecasts. The Tempest API & Developer Platform empowers a growing
community of developers to build useful applications and integrations by
providing access to enhanced data and forecasts from the Tempest System.
Tools are provided to query Tempest Weather station data.

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

## tempestwx Metrics

| Lang | # Files |  (%) | LoC |  (%) | Blank lines |  (%) | # Lines |  (%) |
|:-----|--------:|-----:|----:|-----:|------------:|-----:|--------:|-----:|
| R    |       8 | 0.31 |  72 | 0.22 |          28 | 0.18 |      97 | 0.34 |
| C++  |       2 | 0.08 |  52 | 0.16 |          26 | 0.16 |      15 | 0.05 |
| YAML |       2 | 0.08 |  35 | 0.10 |          10 | 0.06 |       2 | 0.01 |
| Rmd  |       1 | 0.04 |   8 | 0.02 |          15 | 0.09 |      28 | 0.10 |
| SUM  |      13 | 0.50 | 167 | 0.50 |          79 | 0.50 |     142 | 0.50 |

clock Package Metrics for tempestwx

## Code of Conduct

Please note that this project is released with a Contributor Code of
Conduct. By participating in this project you agree to abide by its
terms.
