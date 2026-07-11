//
// Created by Hubert on 11.07.2026.
//

#ifndef CHESS_RAWMOVEHELPERS_H
#define CHESS_RAWMOVEHELPERS_H
#include <cstdint>
#include <vector>

#include "Board.h"
#include "types.h"

struct Delta {
    int8_t dRow{};
    int8_t dCol{};
};

Delta offsetToDelta(int8_t offset);

bool isOnBoard(int col, int row);

std::vector<Position> collectingSlidingMoves(
    const Position& from,
    const Board& board,
    Color myColor,
    const int8_t* offsets,
    size_t offsetCount
);

std::vector<Position> collectJumpMoves(
    const Position& from,
    const Board& board,
    Color myColor,
    const int8_t* offsets,
    size_t offsetCount
);

#endif //CHESS_RAWMOVEHELPERS_H
