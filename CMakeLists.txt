cmake_minimum_required(VERSION 3.27)
project(FinalProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(FinalProject final_part1.cpp
        account.cpp
        account.h
        user.cpp
        user.h)
