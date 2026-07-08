#include "Pawn.h"

#include "Board.h"

std::vector<Position> Pawn::getRawMoves(const Position &from, const Board &board) const {
    std::vector<Position> moves{};
    int direction = (color_ == Color::Black ? 8 : -8);
    uint8_t newSquare = from.square + direction;

    // Move forward
    if (newSquare <= 63 && board.at({newSquare}) == nullptr) {
        moves.push_back({newSquare});

        bool isStartingPos = (color_ == Color::Black ? from.row() == 1 : from.row() == 6);

        if (isStartingPos) {
            uint8_t doubleMove = newSquare + direction;

            if (doubleMove <= 63 && board.at({doubleMove}) == nullptr) {
                moves.push_back({doubleMove});
            }
        }
    }

    // Capture diagonally
    int captureOffset[] = {direction - 1, direction + 1};
    for (const auto& offset : captureOffset) {
        int targetSquare = from.square + offset;

        if (targetSquare <= 63) {
            int targetCol = targetSquare % 8;
            int fromCol = from.col();

            if (fromCol == 0 && targetCol == 7) continue;
            if (fromCol == 7 && targetCol == 0) continue;

            auto figure = board.at({static_cast<uint8_t>(targetSquare)});

            if (figure != nullptr && figure->getColor() != color_) {
                moves.push_back({static_cast<uint8_t>(targetSquare)});
            }
        }
    }


    return moves;
}
