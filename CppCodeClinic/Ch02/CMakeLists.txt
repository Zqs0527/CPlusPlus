cmake_minimum_required(VERSION 3.4.0)
project(WhereAmI VERSION 0.1.0)

include(CTest)
enable_testing()

set(CURL_DIR "C:/Users/yuanc/Repository/vcpkg/packages/curl_x64-windows/share/curl")

find_package(CURL REQUIRED)
add_executable(WhereAmI main.cpp)
target_link_libraries(WhereAmI PRIVATE CURL::libcurl)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
