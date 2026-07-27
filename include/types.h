//
// Created by Hubert on 7.07.2026.
//

#ifndef CHESS_TYPES_H
#define CHESS_TYPES_H
#include "cstdint"
#include <iostream>

struct Position {
    uint8_t square{};

    int row() const { return square/8; }
    int col() const { return square%8; }

    bool operator==(const Position& other) const {
        return square == other.square;
    }
};

enum class FigureType {
    King,
    Queen,
    Rook,
    Bishop,
    Knight,
    Pawn
};

inline char getTypeChar(const FigureType& type) {
    switch (type) {
        case FigureType::Pawn:      return 'P';
        case FigureType::Knight:    return 'N';
        case FigureType::Bishop:    return 'B';
        case FigureType::Rook:      return 'R';
        case FigureType::Queen:     return 'Q';
        case FigureType::King:      return 'K';
        default:                    return '?';
    }
}

enum class Color {
    Black,
    White
};

inline Color opposite(Color c) {
    return c == Color::White ? Color::Black : Color::White;
}

inline int parseSquare(const std::string& s) {
    if (s.size() != 2) return -1;

    int col = s[0] - 'a';
    int rank = s[1] - '0';

    if (col < 0 || col > 7 || rank < 1 || rank > 8) return -1;

    int row = 8 - rank;

    return row * 8 + col;
}

inline std::string toAlgebraic(int sq) {
    char file = 'a' + (sq % 8);
    char rank = '0' + (8 - sq / 8);
    return {file, rank};
}

#endif //CHESS_TYPES_H
