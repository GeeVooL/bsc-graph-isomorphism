cmake_minimum_required(VERSION 3.6)
project(GraphIsomorphism)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++11 -Wall -pedantic -Wextra -Werror")

include_directories(${PROJECT_SOURCE_DIR}/src)
set(SOURCE_FILES src/main.cc src/Graph.cc src/Graph.h src/GraphReader.cc src/GraphReader.h)
add_executable(GraphIsomorphism ${SOURCE_FILES})
