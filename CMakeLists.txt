cmake_minimum_required(VERSION 3.10)
project(OPOSSUM VERSION 0.1.0)

find_package(ROOT 6.26 CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-Wall")


add_subdirectory(src)