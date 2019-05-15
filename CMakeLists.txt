cmake_minimum_required(VERSION 3.13)
project(tictactoe)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Werror -Wextra -pedantic -pedantic-errors -D_GLIBCXX_DEBUG")

set(SOURCE_FILES
        main.cpp
        Player.h
        TicTacToe.h
        TicTacToe.cpp)

add_executable(tictactoe ${SOURCE_FILES})