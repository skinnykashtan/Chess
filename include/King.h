//
// Created by Hubert on 12.07.2026.
//

#ifndef CHESS_KING_H
#define CHESS_KING_H
#include "Figure.h"

class King : public Figure {
public:
    King(Color color) : Figure(color, FigureType::King) {}

    std::vector<Position> getRawMoves(const Position &from, const Board &board) const override;
};

#endif //CHESS_KING_H
