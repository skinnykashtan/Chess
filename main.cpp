#include <iostream>

#include "Board.h"
#include "Pawn.h"

int main() {

    Board board;

    std::unique_ptr<Figure> pawn = std::make_unique<Pawn>(Color::Black);
    std::unique_ptr<Figure> pawn2 = std::make_unique<Pawn>(Color::White);
    board.place(Position{11}, std::move(pawn));
    board.place(Position{55}, std::move(pawn2));

    const Figure* fig = board.at(Position{11});
    const Figure* fig2 = board.at(Position{55});

    std::cout << *fig << "\n";

    auto moves = fig->getRawMoves(Position{11}, board);
    auto moves2 = fig2->getRawMoves(Position{55}, board);

    for (const auto& pos : moves) {
        std::cout << static_cast<int>(pos.square) << "\n";
    }

    std::cout << "\n";
    std::cout << *fig2 << "\n";

    for (const auto& pos : moves2) {
        std::cout << static_cast<int>(pos.square) << "\n";
    }

    return 0;
}
