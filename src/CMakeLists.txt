cmake_minimum_required(VERSION 3.15)
project(chirp_signal_generation)

set(CMAKE_CXX_STANDARD 14)

add_executable(chirp_signal_generation main.cpp ChirpSignal.h ChirpSignal.cpp DataStructure.h Constants.h ToolBox.h)