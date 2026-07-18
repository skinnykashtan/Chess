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

bool Board::isSquareAttacked(Position target, Color by) const {
    for (int row=0; row<8; ++row) {
        for (int col=0; col<8; ++col) {
            const auto& square = squares_[row][col];
            if (square == nullptr) continue;
            if (square->getColor() != by) continue;
            Position from;
            from.square = row*8 + col;

            std::vector<Position> moves = square->getRawMoves(from, *this);
            for (const auto& m : moves) {
                if (m == target) {
                    return true;
                }
            }
        }
    }

    return false;
}

bool Board::isInCheck(Color side) const {
    for (int row=0; row<8; ++row) {
        for (int col=0; col<8; ++col) {
            const auto& figure = squares_[row][col];
            if (figure == nullptr) continue;
            if (figure->getColor() == side && figure->getType() == FigureType::King) {
                uint8_t square = row*8 + col;
                return isSquareAttacked(Position{square}, opposite(side));
            }
        }
    }

    return false;
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


