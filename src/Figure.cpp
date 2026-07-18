#include "Figure.h"

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
