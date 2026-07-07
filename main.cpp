#include <iostream>

#include "Board.h"
#include "Pawn.h"

int main() {

    Board board;

    std::unique_ptr<Figure> pawn = std::make_unique<Pawn>(Color::Black);
    board.place(Position{11}, std::move(pawn));

    auto fig = board.at(Position{11});

    std::cout << *fig << "\n";

    return 0;
}
