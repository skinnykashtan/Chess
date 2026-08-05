#include <iostream>

#include "Game.h"
#include "ui/BoardView.cpp"


int main() {

    Game game{};
    BoardView view{game};

    Move move1{parseSquare("e7"), parseSquare({"e5"})};
    Move move2{parseSquare("f2"), parseSquare("f4")};
    Move move3{parseSquare("d8"), parseSquare("h4")};

    game.board().makeMove(move1);
    game.board().makeMove(move2);
    game.board().makeMove(move3);
    view.draw();

    view.isLegalMovePrint();

    return 0;
}
