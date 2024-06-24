cmake_minimum_required(VERSION 3.20)
project(TerreateLogger)
message(STATUS "Project name : " ${PROJECT_NAME})

function(Configure)
  set(CMAKE_CXX_STANDARD 20)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  set(CMAKE_CXX_EXTENSIONS OFF)
  message(STATUS "C++ standard : " ${CMAKE_CXX_STANDARD})
endfunction()

function(SetIncludes)
  target_include_directories(${PROJECT_NAME} PUBLIC ../includes)
endfunction()

function(SetLibs)

endfunction()

function(Build)
  add_library(${PROJECT_NAME} STATIC defines.cpp manager.cpp)
  set_target_properties(
    ${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
                               LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
  setincludes()
  setlibs()
endfunction()

configure()
build()
