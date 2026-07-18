//
// Created by Hubert on 7.07.2026.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H
#include "Figure.h"
#include <array>
#include <memory>

#include "Move.h"

class Board {
private:
    std::array<std::array<std::unique_ptr<Figure>, 8>, 8> squares_{};
public:
    Board() = default;

    void place(const Position& pos, std::unique_ptr<Figure> figure);

    Figure* at(const Position& pos) const;

    void makeMove(Move& move);

    void unmakeMove(Move& move);

    bool isSquareAttacked(Position square, Color by) const;

    bool isInCheck(Color side) const;

    void print() const;
};

#endif //CHESS_BOARD_H
