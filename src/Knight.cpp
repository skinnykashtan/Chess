#include "Knight.h"

#include "RawMoveHelpers.h"

std::vector<Position> Knight::getRawMoves(const Position &from, const Board &board) const {
    int8_t offsets[] = {17, -17, 15, -15, 6, -6, 10, -10};
    size_t length = std::size(offsets);
    return collectJumpMoves(from, board, color_, offsets, length);
}
