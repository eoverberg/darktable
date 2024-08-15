#ifndef RC_BUILD
  #ifdef HAVE_CONFIG_H
    #include "config.h"
  #endif
  const char darktable_package_version[] = "4.8.1";
  const char darktable_package_string[] = PACKAGE_NAME " 4.8.1";
  const char darktable_last_commit_year[] = "2024";
#else
  #define DT_MAJOR 4
  #define DT_MINOR 8
  #define DT_PATCH 1
  #define DT_N_COMMITS 0
  #define LAST_COMMIT_YEAR "2024"
#endif
