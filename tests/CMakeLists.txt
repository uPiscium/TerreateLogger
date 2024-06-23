cmake_minimum_required(VERSION 3.20)
project(TLTest)

function(Configure)
  set(CMAKE_CXX_STANDARD 20)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  set(CMAKE_CXX_EXTENSIONS OFF)
endfunction()

function(SetLibs)
  target_link_libraries(${PROJECT_NAME} TerreateLogger)
endfunction()

function(SetIncludes)
  target_include_directories(${PROJECT_NAME} PUBLIC ../../includes)
endfunction()

function(Build)
  add_executable(${PROJECT_NAME} TLTest.cpp)
  set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                                   "${CMAKE_BINARY_DIR}/bin")
  setlibs()
  setincludes()
endfunction()

configure()
build()
