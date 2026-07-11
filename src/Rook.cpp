#include "Rook.h"

#include "Board.h"
#include "RawMoveHelpers.h"

std::vector<Position> Rook::getRawMoves(const Position &from, const Board &board) const {
    int8_t offsets[] = {1, -1, 8, -8};
    size_t length = std::size(offsets);
    return collectingSlidingMoves(from, board, color_, offsets, length);
}
