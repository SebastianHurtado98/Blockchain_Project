cmake_minimum_required(VERSION 3.10)
project(ProyectoPOOII)

set(CMAKE_CXX_STANDARD 14)

add_executable(ProyectoPOOII main.cpp Blockchain.cpp Blockchain.h sha256.cpp sha256.h Controller.cpp Controller.h)