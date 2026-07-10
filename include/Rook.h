//
// Created by veest on 09.07.2026.
//

#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H
#include "Figure.h"

class Rook : public Figure {
public:
    Rook(Color color) : Figure(color, FigureType::Rook){}

    std::vector<Position> getRawMoves(const Position &from, const Board &board) const override;

};

#endif //CHESS_ROOK_H
