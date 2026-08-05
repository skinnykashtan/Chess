#include "Board.h"

#include <algorithm>

#include "Figure.h"

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

void Board::clear() {
    sideToMove_ = Color::White;

    for (int row=0; row<8; ++row) {
        for (int col=0; col<8; ++col) {
            squares_[row][col] = nullptr;
        }
    }
}

void Board::setupStartingPosition() {
    clear();

    FigureType backRank[] = {
        FigureType::Rook, FigureType::Knight, FigureType::Bishop, FigureType::Queen, FigureType::King, FigureType::Bishop, FigureType::Knight, FigureType::Rook
    };
    // BLACK
    for (int col=0; col<8; col++) {
        squares_[0][col] = Figure::makeFigure(Color::Black, backRank[col]);
        squares_[1][col] = Figure::makeFigure(Color::Black, FigureType::Pawn);
    }

    // WHITE
    for (int col=0; col<8; col++) {
        squares_[7][col] = Figure::makeFigure(Color::White, backRank[col]);
        squares_[6][col] = Figure::makeFigure(Color::White, FigureType::Pawn);
    }
}

bool Board::isLegalMove(Move& move) {
    if (move.from.square < 0 || move.from.square > 63) return false;

    const auto& figure = at(Position{move.from});
    std::vector<Position> moves = figure->getRawMoves(Position{move.from}, *this);

    for (std::size_t i=0; i<moves.size(); i++) {
        if (move.to == moves[i]) {
            makeMove(move);
            bool legal = !isInCheck(figure->getColor());
            unmakeMove(move);

            if (legal) {
                return true;
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


