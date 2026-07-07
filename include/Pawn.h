//
// Created by Hubert on 7.07.2026.
//

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H
#include "Figure.h"

class Pawn : public Figure {
public:
    Pawn(Color color) : Figure(color, FigureType::Pawn) {}
};

#endif //CHESS_PAWN_H
