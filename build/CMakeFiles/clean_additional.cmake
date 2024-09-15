# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "RelWithDebInfo")
  file(REMOVE_RECURSE
  "CMakeFiles/app_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/app_autogen.dir/ParseCache.txt"
  "app_autogen"
  )
endif()
