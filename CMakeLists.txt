cmake_minimum_required(VERSION 3.12.4)

IF(DEFINED ENV{TRAVIS_BUILD_NUMBER})
  set(VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
ELSE()  
  set(VERSION 0.0.1)
ENDIF()

project(timus VERSION ${VERSION})

set(CMAKE_CXX_STANDARD 17)

set(SRC_PATH "src")

# https://stackoverflow.com/a/14307434
file( GLOB APP_SOURCES ${SRC_PATH}/*.cpp ) 
foreach( sourcefile ${APP_SOURCES} ) 
  get_filename_component(file ${sourcefile} NAME_WE)
  add_executable( ${file} ${sourcefile} ) 
endforeach( sourcefile ${APP_SOURCES} )