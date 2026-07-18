cmake_minimum_required(VERSION 3.28)
project(Chess)

set(CMAKE_CXX_STANDARD 20)

add_library(chess_lib
        src/Board.cpp
        src/Figure.cpp
        src/Pawn.cpp
        src/Rook.cpp
        src/RawMoveHelpers.cpp
        src/Queen.cpp
        src/Bishop.cpp
        src/King.cpp
        src/Knight.cpp
)
target_include_directories(chess_lib PUBLIC include)

add_executable(Chess
        main.cpp
)
target_link_libraries(Chess PRIVATE chess_lib)

# --- GoogleTest ---
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(chess_tests
    tests/test_board.cpp
)
target_link_libraries(chess_tests
    PRIVATE
        chess_lib
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(chess_tests)
