#include "King.h"

#include "RawMoveHelpers.h"

std::vector<Position> King::getRawMoves(const Position &from, const Board &board) const {
    int8_t offsets[] = {1, -1, 8, -8, 9, 7, -7, -9};
    int8_t length = std::size(offsets);
    return collectJumpMoves(from, board, color_, offsets, length);
}
