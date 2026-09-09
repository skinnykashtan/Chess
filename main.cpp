#include <iostream>

#include "Game.h"
#include "ui/BoardView.cpp"
#include "Board.h"


int main() {

    Game game{};
    BoardView view{game};
    Color color = Color::White;

    while (game.result() == GameResult::Playing) {
        view.draw();

        while (true) {
            std::string colorMoving = color == Color::White ? "White's turn: " : "Black's turn: ";
            std::cout << colorMoving;

            std::string from, to;
            if (!(std::cin >> from >> to)) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Input error! Try Again." << '\n';
                continue;
            }

            if (!isCorrectNotation(from) || !isCorrectNotation(to)) {
                std::cout << "Invalid format; Correct Format ex.(e1 e3)" << '\n';
                continue;
            }

            uint8_t parsedFrom = parseSquare(from);
            uint8_t parsedTo = parseSquare(to);
            Move move{parsedFrom, parsedTo};

            if (view.isMoveCorrect(color, move)) {
                game.board().makeMove(move);
                view.draw();
                std::cout << getColor(color) << " Moved from: " << from << ", to: " << to << '\n';
            } else {
                std::cout << "Forbidden move, try again." << '\n';
                continue;
            }

            color = opposite(color);
            break;
        }
    }

    return 0;
}
