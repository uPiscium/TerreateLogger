cmake_minimum_required(VERSION 3.20)
project(test)

option(TERREATE_LOGGER_BUILD_TESTS "Build tests" ON)

add_subdirectory(impls)

if(TERREATE_LOGGER_BUILD_TESTS)
  add_subdirectory(tests)
endif()
