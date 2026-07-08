#include "Pawn.h"

#include "Board.h"

std::vector<Position> Pawn::getRawMoves(const Position &from, const Board &board) const {
    std::vector<Position> moves{};
    int direction = (color_ == Color::Black ? 8 : -8);
    uint8_t newSquare = from.square + direction;

    if (newSquare <= 63 && board.at({newSquare}) == nullptr) {
        moves.push_back({newSquare});

        bool isStaringPos = (color_ == Color::Black ? from.row() == 1 : from.row() == 6);

        if (isStaringPos) {
            uint8_t doubleMove = newSquare + direction;
            moves.push_back({doubleMove});
        }
    }

    return moves;
}
