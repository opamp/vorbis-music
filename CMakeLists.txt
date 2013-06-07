PROJECT(vorbis-music)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.10)

SET(CMAKE_BUILD_TYPE Release) #Rewrite "Debug" if you want binary for debug.
SET(SRC_DIR ${PROJECT_SOURCE_DIR}/src)

INCLUDE(${SRC_DIR}/CMakeLists.txt)
