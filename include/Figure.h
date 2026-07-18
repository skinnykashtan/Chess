//
// Created by Hubert on 7.07.2026.
//

#ifndef CHESS_FIGURE_H
#define CHESS_FIGURE_H
#include <iosfwd>
#include <vector>
#include "types.h"

class Board;

class Figure {
protected:
    Color color_;
    FigureType type_;
public:
    Figure(Color color, FigureType type) : color_(color), type_(type) {}

    virtual ~Figure() = default;

    virtual std::vector<Position> getRawMoves(const Position& from, const Board& board) const = 0;

    Color getColor() const;

    FigureType getType() const;

    friend std::ostream& operator<<(std::ostream& os, const Figure& figure);
};

#endif //CHESS_FIGURE_H
