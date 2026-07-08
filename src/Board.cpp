#include "Board.h"

void Board::place(const Position& pos, std::unique_ptr<Figure> figure) {
    if (squares_[pos.row()][pos.col()] == nullptr) {
        squares_[pos.row()][pos.col()] = std::move(figure);
    }
}

Figure* Board::at(const Position& pos) const {
    return squares_[pos.row()][pos.col()].get();
}



