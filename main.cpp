#include <iostream>

#include "Bishop.h"
#include "Board.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"

int main() {

    Board board;

    std::unique_ptr<Figure> pawn = std::make_unique<Pawn>(Color::Black);
    std::unique_ptr<Figure> pawn2 = std::make_unique<Pawn>(Color::White);
    std::unique_ptr<Figure> rook = std::make_unique<Rook>(Color::Black);
    std::unique_ptr<Figure> bishop = std::make_unique<Bishop>(Color::Black);
    std::unique_ptr<Figure> queen = std::make_unique<Queen>(Color::Black);
    board.place(Position{11}, std::move(pawn));
    board.place(Position{18}, std::move(pawn2));
    board.place(Position{17}, std::move(rook));
    board.place(Position{19}, std::move(bishop));
    board.place(Position{20}, std::move(queen));

    const Figure* fig = board.at(Position{11});
    const Figure* fig2 = board.at(Position{18});
    const Figure* fig3 = board.at(Position{17});
    const Figure* fig4 = board.at(Position{19});
    const Figure* fig5 = board.at(Position{20});

    std::cout << *fig << "\n";

    auto moves = fig->getRawMoves(Position{11}, board);
    auto moves2 = fig2->getRawMoves(Position{18}, board);
    auto moves3 = fig3->getRawMoves(Position{17}, board);
    auto moves4 = fig4->getRawMoves(Position{19}, board);
    auto moves5 = fig5->getRawMoves(Position{20}, board);

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

    std::cout << "\n";
    std::cout << *fig4 << "\n";

    for (const auto& pos : moves4) {
        std::cout << static_cast<int>(pos.square) << "\n";
    }

    std::cout << "\n";
    std::cout << *fig5 << "\n";

    for (const auto& pos : moves5) {
        std::cout << static_cast<int>(pos.square) << "\n";
    }

    return 0;
}
