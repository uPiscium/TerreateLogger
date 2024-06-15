cmake_minimum_required(VERSION 3.20)
project(TLTest)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

function(SetLibs)
  target_link_libraries(${PROJECT_NAME} TerreateLogger)
endfunction()

function(SetIncludes)
  target_include_directories(${PROJECT_NAME} PUBLIC ../../includes)
endfunction()

function(Build)
  add_executable(${PROJECT_NAME} TLTest.cpp)
  setlibs()
  setincludes()
endfunction()

build()
