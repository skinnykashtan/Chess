#include "Figure.h"

#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"

std::ostream& operator<<(std::ostream& os, const Figure& figure) {
    char symbol = getTypeChar(figure.type_);

    if (figure.color_ == Color::White) {
        symbol = std::tolower(static_cast<unsigned char>(symbol));
    }

    os << symbol;
    return os;
}

Color Figure::getColor() const {
    return color_;
}

FigureType Figure::getType() const {
    return type_;
}

std::unique_ptr<Figure> Figure::makeFigure(Color color, FigureType type) {
    switch (type) {
        case FigureType::Pawn: return std::make_unique<Pawn>(color);
        case FigureType::Knight: return std::make_unique<Knight>(color);
        case FigureType::Rook: return std::make_unique<Rook>(color);
        case FigureType::Queen: return std::make_unique<Queen>(color);
        case FigureType::King: return std::make_unique<King>(color);
        case FigureType::Bishop: return std::make_unique<Bishop>(color);
    }
    return nullptr;
}
