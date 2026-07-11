//
// Created by Hubert on 11.07.2026.
//

#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H
#include "Figure.h"

class Queen : public Figure {
public:
    Queen(Color color) : Figure(color, FigureType::Queen){}

    std::vector<Position> getRawMoves(const Position &from, const Board &board) const override;
};

#endif //CHESS_QUEEN_H
