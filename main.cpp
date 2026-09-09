#include <iostream>

#include "Game.h"
#include "ui/BoardView.cpp"
#include "Board.h"


int main() {

    Game game{};
    BoardView view{game};

    std::string from;
    std::string to;
    bool correctInput = false;

    while (game.result() == GameResult::Playing) {
        view.draw();

        while (!correctInput) {
            std::cout << "White's turn: ";
            std::cin >> from >> to;
            Move move{parseSquare(from), parseSquare(to)};

            if (game.board().at(Position{parseSquare(from)})->getColor() == Color::White && game.board().isLegalMove(move)) {
                game.board().makeMove(move);
                view.draw();
                break;
            }

            std::cout << "Wrong move; Correct Format ex.(e1 e3)" << "\n";
        }


        while (!correctInput) {
            std::cout << "Black's turn: ";
            std::cin >> from >> to;
            Move move{parseSquare(from), parseSquare(to)};

            if (game.board().at(Position{parseSquare(from)})->getColor() == Color::Black && game.board().isLegalMove(move)) {
                game.board().makeMove(move);
                view.draw();
                break;
            }

            std::cout << "Wrong move; Correct Format ex.(e1 e3)" << "\n";
        }
    }

    return 0;
}
