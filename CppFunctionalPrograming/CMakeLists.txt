cmake_minimum_required(VERSION 3.7)
project(Ch3)

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
set(BOOST_ROOT C:/boost) 

find_package(Boost 1.79.0)

# find_package(PkgConfig)

# if(NOT EXISTS "${rxcpp_INCLUDE_DIR}")
#   find_path(rxcpp_INCLUDE_DIR
#     NAMES rxcpp/rx.hpp 
#     DOC "rxcpp library header files"
#     )
# endif()

# if(EXISTS "${rxcpp_INCLUDE_DIR}")
#   include(FindPackageHandleStandardArgs)
#   mark_as_advanced(rxcpp_INCLUDE_DIR)
# else()
#   include(ExternalProject)
#   ExternalProject_Add(rxcpp
#     GIT_REPOSITORY https://github.com/Reactive-Extensions/RxCpp.git
#     TIMEOUT 5
#     CMAKE_ARGS -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER} -DCMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}
#     PREFIX "${CMAKE_CURRENT_BINARY_DIR}"
#     CONFIGURE_COMMAND "" # Disable configure step
#     BUILD_COMMAND "" # Disable build step
#     INSTALL_COMMAND "" # Disable install step
#     UPDATE_COMMAND "" # Disable update step: clones the project only once
#     )
  
#   # Specify include dir
#   ExternalProject_Get_Property(rxcpp source_dir)
#   set(rxcpp_INCLUDE_DIR ${source_dir}/Rx/v2/src)
# endif()

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
    LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
    add_executable(Ch3 "Ch3.cpp")
    target_link_libraries(Ch3 ${Boost_LIBRARIES})
else()
    message(STATUS "Fail asdasd!")
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 17)
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
