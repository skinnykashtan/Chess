//
// Created by Hubert on 12.07.2026.
//

#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H
#include "Figure.h"

class Knight : public Figure {
public:
    Knight(Color color) : Figure(color, FigureType::Knight){}

    std::vector<Position> getRawMoves(const Position &from, const Board &board) const override;
};

#endif //CHESS_KNIGHT_H
