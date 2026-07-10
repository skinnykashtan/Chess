#include "Rook.h"

#include "Board.h"

std::vector<Position> Rook::getRawMoves(const Position &from, const Board &board) const {
    std::vector<Position> moves{};

    int8_t offsets[] = {1, -1, 8, -8};

    for (int8_t offset : offsets) {
        for (int i = 1; i<=7; i++) {

            uint8_t targetSquare = from.square + (i * offset);

            if (targetSquare > 63) {
                break;
            }

            if (offset == 1 || offset == -1) {
                int targetRow = targetSquare / 8;
                if (targetRow != from.row()) {
                    break;
                }
            }

            auto figure = board.at({targetSquare});

            if (figure == nullptr) {
                moves.push_back({targetSquare});
            } else {
                if (figure->getColor() != color_) {
                    moves.push_back({targetSquare});
                }
                break;
            }
        }
    }

    return moves;
}
