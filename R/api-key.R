#' Get or set TEMPEST_PAT value
#'
#' The API wrapper functions in this package all rely on a Tempest Weather
#' personal access token residing in the environment variable \code{TEMPEST_PAT}. The
#' easiest way to accomplish this is to set it in the `\code{.Renviron}` file in your
#' home directory.
#'
#' Go [here](https://tempestwx.com/settings/tokens) to generate a personal access token.
#'
#' @param force force setting a new Tempest PAT for the current environment?
#' @return atomic character vector containing the Tempest Weather PAT
#' @references [Tempest API](https://weatherflow.github.io/Tempest/api/)
#' @export
tempest_pat <- function(force = FALSE) {

  env <- Sys.getenv('TEMPEST_PAT')
  if (!identical(env, "") && !force) return(env)

  if (!interactive()) {
    stop("Please set env var TEMPEST_PAT to your Tempest Weather personal access token.",
         call. = FALSE)
  }

  message("Couldn't find env var TEMPEST_PAT See ?tempest_pat for more details.")
  message("Please enter your API key and press enter:")
  pat <- readline(": ")

  if (identical(pat, "")) {
    stop("Tempest Weather personal access token entry failed", call. = FALSE)
  }

  message("Updating TEMPEST_PAT env var")
  Sys.setenv(TEMPEST_PAT = pat)

  pat

}