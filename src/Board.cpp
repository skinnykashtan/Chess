#include "Board.h"

void Board::place(const Position& pos, std::unique_ptr<Figure> figure) {
    if (squares_[pos.row()][pos.col()] == nullptr) {
        squares_[pos.row()][pos.col()] = std::move(figure);
    }
}

Figure* Board::at(const Position& pos) const {
    return squares_[pos.row()][pos.col()].get();
}

void Board::makeMove(Move &move) {
    auto& fromCell = squares_[move.from.row()][move.from.col()];

    auto& toCell = squares_[move.to.row()][move.to.col()];

    if (at(move.to) != nullptr) {
        move.figureCaptured = std::move(toCell);
    }

    toCell = std::move(fromCell);
    fromCell = nullptr;
}

void Board::unmakeMove(Move &move) {
    auto& fromCell = squares_[move.from.row()][move.from.col()];

    auto& toCell = squares_[move.to.row()][move.to.col()];

    fromCell = std::move(toCell);
    toCell = std::move(move.figureCaptured);
}

void Board::print() const {
    for (int row=0; row<8; ++row) {
        for (int col=0; col<8; ++col) {
            const auto& square = squares_[row][col];
            if (square == nullptr) {
                std::cout << ". ";
            } else {
                std::cout << *square << ' ';
            }
        }
        std::cout << "\n";
    }
    std::cout << "a b c d e f g h\n";
}


