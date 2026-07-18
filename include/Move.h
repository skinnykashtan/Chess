//
// Created by Hubert on 18.07.2026.
//

#ifndef CHESS_MOVE_H
#define CHESS_MOVE_H
#include <memory>

#include "Figure.h"
#include "types.h"

struct Move {
    Position from;
    Position to;

    std::unique_ptr<Figure> figureCaptured;
};

#endif //CHESS_MOVE_H
