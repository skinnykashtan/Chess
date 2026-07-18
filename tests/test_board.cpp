#include <gtest/gtest.h>
#include "Board.h"
#include "King.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"

class BoardTest : public ::testing::Test {
protected:
    Board board;
};

TEST_F(BoardTest, KingInCheckFromRook) {

    board.place(Position{4}, std::make_unique<King>(Color::Black));
    board.place(Position{0}, std::make_unique<Rook>(Color::White));

    EXPECT_TRUE(board.isInCheck(Color::Black));
    EXPECT_FALSE(board.isInCheck(Color::White));
}

TEST_F(BoardTest, MakeMoveAndUnmakeMove) {
    board.place(Position{10}, std::make_unique<Pawn>(Color::Black));

    Move move{Position{10}, Position{18}};
    board.makeMove(move);

    EXPECT_EQ(board.at(Position{10}), nullptr);
    ASSERT_NE(board.at(Position{18}), nullptr);
    EXPECT_EQ(board.at(Position{18})->getType(), FigureType::Pawn);

    board.unmakeMove(move);

    ASSERT_NE(board.at(Position{10}), nullptr);
    EXPECT_EQ(board.at(Position{10})->getType(), FigureType::Pawn);
    EXPECT_EQ(board.at(Position{18}), nullptr);
}

TEST_F(BoardTest, RawMovesForQueen) {
    board.place(Position{59}, std::make_unique<Queen>(Color::Black));

    ASSERT_NE(board.at(Position{59}), nullptr);

    auto moves = board.at(Position{59})->getRawMoves(Position{59}, board);

    ASSERT_EQ(moves.size(), 21u);

    board.place(Position{51}, std::make_unique<Pawn>(Color::Black));
    moves = board.at(Position{59})->getRawMoves(Position{59}, board);

    EXPECT_EQ(
        std::find(moves.begin(), moves.end(), Position{51}),
        moves.end()
    );
}

TEST_F(BoardTest, isSquareAttacked) {
    board.place(Position{59}, std::make_unique<Queen>(Color::Black));
    board.place(Position{51}, std::make_unique<Pawn>(Color::White));

    ASSERT_FALSE(board.isSquareAttacked(Position{59}, Color::Black));
    EXPECT_TRUE(board.isSquareAttacked(Position{51}, Color::Black));
    EXPECT_FALSE(board.isSquareAttacked(Position{42}, Color::White));

    board.place(Position{42}, std::make_unique<Pawn>(Color::Black));
    EXPECT_TRUE(board.isSquareAttacked(Position{42}, Color::White));
}


