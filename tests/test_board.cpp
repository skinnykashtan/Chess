#include <gtest/gtest.h>
#include "Board.h"
#include "King.h"
#include "Rook.h"

TEST(BoardCheckTest, KingInCheckFromRook) {
    Board board;

    board.place(Position{4}, std::make_unique<King>(Color::Black));
    board.place(Position{0}, std::make_unique<Rook>(Color::White));

    EXPECT_TRUE(board.isInCheck(Color::Black));
    EXPECT_FALSE(board.isInCheck(Color::White));
}