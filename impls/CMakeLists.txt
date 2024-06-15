cmake_minimum_required(VERSION 3.20)
project(TerreateLogger)
message(STATUS "Project name : " ${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
message(STATUS "C++ standard : " ${CMAKE_CXX_STANDARD})

function(SetIncludes)
  target_include_directories(${PROJECT_NAME} PUBLIC ../includes)
endfunction()

function(SetLibs)

endfunction()

function(Build)
  add_library(${PROJECT_NAME} STATIC manager.cpp)
  setincludes()
  setlibs()
endfunction()

build()
