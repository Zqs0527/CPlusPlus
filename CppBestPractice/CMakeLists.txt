cmake_minimum_required(VERSION 3.7.0)
project(CppBestPractice VERSION 0.1.0)

include(CTest)
enable_testing()

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
set(BOOST_ROOT C:/boost) 

find_package(Boost 1.79.0 REQUIRED COMPONENTS filesystem)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
    LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
    add_executable(CppBestPractice "main.cpp")
    target_link_libraries(CppBestPractice ${Boost_LIBRARIES})
else()
    message(STATUS "Fail asdasd!")
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
