#include "RawMoveHelpers.h"

Delta offsetToDelta(int8_t offset) {
    switch (offset) {
        case 1: return {0, 1};
        case -1: return {0, -1};
        case 8: return {1, 0};
        case -8: return {-1, 0};
        case 9: return {1, 1};
        case -9: return {-1, -1};
        case 7: return {1, -1};
        case -7: return {-1, 1};
        default: return {0 ,0};
    }
}

bool isOnBoard(int col, int row) {
    return row >= 0 && row <= 7 && col >= 0 && col <= 7;
}

std::vector<Position> collectingSlidingMoves(const Position &from, const Board &board, Color myColor, const int8_t *offsets, size_t offsetCount) {
    std::vector<Position> moves{};

    for (size_t d=0; d<offsetCount; d++) {
        int8_t offset = offsets[d];
        auto [dRow, dCol] = offsetToDelta(offset);

        for (int i = 1; i<=7; i++) {
            int row = from.row() + dRow * i;
            int col = from.col() + dCol * i;

            if (!isOnBoard(col, row)) {
                break;
            }

            uint8_t targetSquare = col + row * 8;

            auto figure = board.at({targetSquare});

            if (figure == nullptr) {
                moves.push_back({targetSquare});
            } else {
                if (figure->getColor() != myColor) {
                    moves.push_back({targetSquare});
                }
                break;
            }
        }
    }

    return moves;
}
