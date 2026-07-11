#include "Queen.h"

#include "RawMoveHelpers.h"

std::vector<Position> Queen::getRawMoves(const Position &from, const Board &board) const {
    int8_t offsets[] = {1, -1, 8, -8, 9, 7, -7, -9};
    size_t offsetCount = std::size(offsets);
    return collectingSlidingMoves(from, board, color_, offsets, offsetCount);
}
