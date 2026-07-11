//
// Created by Hubert on 11.07.2026.
//

#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H
#include "Figure.h"

class Bishop : public Figure {
public:
    Bishop(Color color) : Figure(color, FigureType::Bishop){}

    std::vector<Position> getRawMoves(const Position &from, const Board &board) const override;
};

#endif //CHESS_BISHOP_H
