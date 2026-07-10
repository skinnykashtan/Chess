#include <iostream>

#include "Board.h"
#include "Pawn.h"
#include "Rook.h"

int main() {

    Board board;

    std::unique_ptr<Figure> pawn = std::make_unique<Pawn>(Color::Black);
    std::unique_ptr<Figure> pawn2 = std::make_unique<Pawn>(Color::White);
    std::unique_ptr<Figure> rook = std::make_unique<Rook>(Color::Black);
    board.place(Position{11}, std::move(pawn));
    board.place(Position{18}, std::move(pawn2));
    board.place(Position{17}, std::move(rook));

    const Figure* fig = board.at(Position{11});
    const Figure* fig2 = board.at(Position{18});
    const Figure* fig3 = board.at(Position{17});

    std::cout << *fig << "\n";

    auto moves = fig->getRawMoves(Position{11}, board);
    auto moves2 = fig2->getRawMoves(Position{18}, board);
    auto moves3 = fig3->getRawMoves(Position{17}, board);

    for (const auto& pos : moves) {
        std::cout << static_cast<int>(pos.square) << "\n";
    }

    std::cout << "\n";
    std::cout << *fig2 << "\n";

    for (const auto& pos : moves2) {
        std::cout << static_cast<int>(pos.square) << "\n";
    }

    std::cout << "\n";
    std::cout << *fig3 << "\n";

    for (const auto& pos : moves3) {
        std::cout << static_cast<int>(pos.square) << "\n";
    }

    return 0;
}
