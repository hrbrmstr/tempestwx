httr::user_agent(
  sprintf(
    "tempestwx R package v%s: (<%s>)",
    utils::packageVersion("tempestwx"),
    utils::packageDescription("tempestwx")$URL
  )
) -> .TEMPEST_UA

.pkg <- new.env(parent = emptyenv())