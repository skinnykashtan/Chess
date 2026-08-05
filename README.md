# Chess

A chess project written in C++.

I started it to practise object-oriented programming and to understand how chess rules can be represented in code. The project is still in progress, so some rules and the full game loop are not implemented yet.

## What works now

- board representation and standard starting position
- separate classes for chess pieces
- pseudo-legal move generation
- captures
- making and undoing moves
- square attack detection
- basic check detection
- conversion between board indexes and chess notation, for example `e4`
- console board display
- selected unit tests with GoogleTest

## Example board

```text
8   r n b q k b n r
7   p p p p p p p p
6   . . . . . . . .
5   . . . . . . . .
4   . . . . . . . .
3   . . . . . . . .
2   P P P P P P P P
1   R N B Q K B N R

    a b c d e f g h
```

Uppercase letters are White pieces and lowercase letters are Black pieces.

## Technologies

- C++20
- CMake
- GoogleTest
- STL

## Project structure

```text
include/   headers and piece declarations
src/       board, game and piece implementations
tests/     unit tests
ui/        console board view
main.cpp   application entry point
```

## Build

Requirements:

- C++20-compatible compiler
- CMake
- Git

```bash
git clone https://github.com/skinnykashtan/Chess.git
cd Chess

cmake -S . -B build
cmake --build build
```

Run the program on Linux:

```bash
./build/Chess
```

Run tests:

```bash
ctest --test-dir build --output-on-failure
```

## Next steps

- legal move validation
- turn-based game loop
- checkmate and stalemate detection
- castling
- en passant
- pawn promotion
- more unit tests

