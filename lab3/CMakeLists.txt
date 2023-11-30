cmake_minimum_required(VERSION 3.27)
include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.11.0
)

FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

set(CMAKE_CXX_STANDARD 17)

project(lab3)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)

include_directories(${INCLUDE_DIR})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES false figures.cpp point.cpp rectangle.cpp rhombus.cpp trapezoid.cpp)
file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false test.cpp)

add_library(${CMAKE_PROJECT_NAME}_lib ${SOURCES})
add_executable(${CMAKE_PROJECT_NAME}_exe main.cpp)
add_executable(${CMAKE_PROJECT_NAME}_test ${TEST_SOURCES})

target_link_libraries(${CMAKE_PROJECT_NAME}_exe PRIVATE ${CMAKE_PROJECT_NAME}_lib)
target_include_directories(${CMAKE_PROJECT_NAME}_test PRIVATE ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
target_link_libraries(${CMAKE_PROJECT_NAME}_test PRIVATE ${CMAKE_PROJECT_NAME}_lib gtest gtest_main)

find_package(Threads REQUIRED) 
target_link_libraries(${CMAKE_PROJECT_NAME}_test PRIVATE Threads::Threads) 


add_test(NAME BASIC COMMAND tests)
