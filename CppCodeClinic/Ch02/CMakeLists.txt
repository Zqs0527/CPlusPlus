cmake_minimum_required(VERSION 3.22.0)
project(WhereAmI VERSION 0.1.0)

include(CTest)
enable_testing()
set(CURL_LIBRARY "C:/msys64/mingw64/lib/libcurl.dll.a")

find_package(CURL REQUIRED)
add_executable(WhereAmI main.cpp)
add_library(cJSON STATIC cJSON.c)


target_link_libraries(WhereAmI PRIVATE CURL::libcurl cJSON)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
