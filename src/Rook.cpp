#include "Rook.h"

#include "Board.h"

std::vector<Position> Rook::getRawMoves(const Position &from, const Board &board) const {
    std::vector<Position> moves{};
    constexpr uint8_t availableMoves = 7;

    for (uint8_t i=1; i<=availableMoves; i++) {
        uint8_t rightSquare = from.square + i;
        if (rightSquare <= 63 && from.col() + i <= 7) {

        }

        uint8_t leftSquare = from.square - i;
        if (leftSquare <= 63 && from.col() - i >= 0) {

        }
    }
}
