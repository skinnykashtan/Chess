#include "Game.h"

class BoardView {
private:
    Game &game_;

public:
    explicit BoardView(Game &game) : game_(game) {
    }

    void draw() {
        Board &board = game_.board();

        std::cout << "\n";

        for (int row = 0; row < 8; ++row) {
            std::cout << 8 - row << "   ";
            for (int col = 0; col < 8; ++col) {
                uint8_t square = row * 8 + col;
                const auto &figure = board.at({square});

                if (figure == nullptr) {
                    std::cout << ". ";
                } else {
                    std::cout << *figure << ' ';
                }
            }
            std::cout << "\n";
        }
        std::cout << "\n";
        std::cout << "    a b c d e f g h\n";
    }

    void isLegalMovePrint() {
        Board &board = game_.board();
        Move move{Position{parseSquare("g2")}, Position{parseSquare("g3")}};

        if (board.isLegalMove(move)) {
            std::cout << "true " << move.to.square;
        } else {
            std::cout << "false " << move.to.square;
        }
    }

    bool isMoveCorrect(Color color, Move& move) {
        if (game_.board().at(Position{move.from})->getColor() == color && game_.board().isLegalMove(move)) {
            return true;
        }

        return false;
    }
};
