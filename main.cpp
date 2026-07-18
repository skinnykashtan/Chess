#include <iostream>

#include "Bishop.h"
#include "Board.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"

int main() {

    Board board;

    std::unique_ptr<Figure> pawn = std::make_unique<Pawn>(Color::Black);
    std::unique_ptr<Figure> pawn2 = std::make_unique<Pawn>(Color::White);
    std::unique_ptr<Figure> rook = std::make_unique<Rook>(Color::White);
    std::unique_ptr<Figure> bishop = std::make_unique<Bishop>(Color::Black);
    std::unique_ptr<Figure> queen = std::make_unique<Queen>(Color::Black);
    std::unique_ptr<Figure> king = std::make_unique<King>(Color::Black);
    std::unique_ptr<Figure> knight = std::make_unique<Knight>(Color::Black);

    board.place(Position{52}, std::move(pawn));
    board.place(Position{18}, std::move(pawn2));
    board.place(Position{63}, std::move(rook));
    board.place(Position{11}, std::move(bishop));
    board.place(Position{59}, std::move(queen));
    board.place(Position{60}, std::move(king));
    board.place(Position{57}, std::move(knight));

    const Figure* fig = board.at(Position{52});
    const Figure* fig2 = board.at(Position{18});
    const Figure* fig3 = board.at(Position{63});
    const Figure* fig4 = board.at(Position{11});
    const Figure* fig5 = board.at(Position{59});
    const Figure* fig6 = board.at(Position{60});
    const Figure* fig7 = board.at(Position{57});

    auto moves = fig->getRawMoves(Position{52}, board);
    auto moves2 = fig2->getRawMoves(Position{18}, board);
    auto moves3 = fig3->getRawMoves(Position{63}, board);
    auto moves4 = fig4->getRawMoves(Position{11}, board);
    auto moves5 = fig5->getRawMoves(Position{59}, board);
    auto moves6 = fig6->getRawMoves(Position{60}, board);
    auto moves7 = fig7->getRawMoves(Position{57}, board);

    std::cout << *fig << "\n";

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

    std::cout << "\n";
    std::cout << *fig6 << "\n";

    for (const auto& pos : moves6) {
        std::cout << static_cast<int>(pos.square) << "\n";
    }

    std::cout << "\n";
    std::cout << *fig7 << "\n";

    for (const auto& pos : moves7) {
        std::cout << static_cast<int>(pos.square) << "\n";
    }

    board.print();

    std::cout << board.isInCheck(Color::Black) << '\n';

    // makeMove test
    Move move{Position{63}, Position{55}};
    board.makeMove(move);
    board.print();
    std::cout << board.isInCheck(Color::Black) << '\n';

    Move move2{Position{55}, Position{63}};
    board.makeMove(move2);
    board.print();
    std::cout << board.isInCheck(Color::Black) << '\n';

    // unmakeMove test
    board.unmakeMove(move2);
    board.print();

    return 0;
}
