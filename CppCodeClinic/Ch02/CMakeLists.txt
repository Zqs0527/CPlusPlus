cmake_minimum_required(VERSION 3.22.0)
project(WhereAmI VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(CURL REQUIRED)
file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "*.c")
add_executable(WhereAmI ${SOURCES})
target_link_libraries(WhereAmI PRIVATE CURL::libcurl)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
