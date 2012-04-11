############################################
# CMake File for OpenGL Utility Library glul
############################################
cmake_minimum_required(VERSION 2.8) 

project(spaceg)

# C++11
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -std=c++11")

# Set up executable
file(GLOB_RECURSE SPACEG_SOURCES src/*.cpp)

add_executable(spaceg ${SPACEG_SOURCES})
target_link_libraries(spaceg 
                      "GL" "GLEW" 
                      "sfml-system" "sfml-window" "sfml-graphics" "sfml-audio" 
                      "RocketCore" "RocketControls" "RocketDebugger"
                      "lua")
