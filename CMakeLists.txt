cmake_minimum_required(VERSION 3.28)
project(Chess)

set(CMAKE_CXX_STANDARD 20)

add_executable(Chess
        main.cpp
        src/Board.cpp
        src/Figure.cpp
        src/Pawn.cpp
        src/Rook.cpp
        src/RawMoveHelpers.cpp
)

target_include_directories(Chess PUBLIC include)
