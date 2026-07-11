#include "Bishop.h"

#include "RawMoveHelpers.h"

std::vector<Position> Bishop::getRawMoves(const Position &from, const Board &board) const {
    int8_t offsets[] = {9, 7, -7, -9};
    size_t offsetCount = std::size(offsets);
    return collectingSlidingMoves(from, board, color_, offsets, offsetCount);
}
