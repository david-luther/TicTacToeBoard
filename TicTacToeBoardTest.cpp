/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/

TEST(TicTacToeBoardTest, toggleTurnOnce)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.toggleTurn(), O);
}

TEST(TicTacToeBoardTest, toggleTurnTwice)
{
	TicTacToeBoard board;
	board.toggleTurn();
	ASSERT_EQ(board.toggleTurn(), X);
}

TEST(TicTacToeBoardTest, toggleTurnThreeTimes)
{
	TicTacToeBoard board;
	board.toggleTurn();
	board.toggleTurn();
	ASSERT_EQ(board.toggleTurn(), O);
}

TEST(TicTacToeBoardTest, placePieceFirstMove)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(0,0), X);
}

TEST(TicTacToeBoardTest, placePieceSecondMove)
{
	TicTacToeBoard board;
	board.placePiece(0,0);
	ASSERT_EQ(board.placePiece(0,1), O);
}

TEST(TicTacToeBoardTest, placePieceInvalidRow)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(3,0), Invalid);
}

TEST(TicTacToeBoardTest, placePieceInvalidColumn)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(0,3), Invalid);
}

TEST(TicTacToeBoardTest, placePieceAlreadyPlaced)
{
	TicTacToeBoard board;
	board.placePiece(0,0);
	ASSERT_EQ(board.placePiece(0,0), X);
}

TEST(TicTacToeBoardTest, placePieceNegativeRow)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(-1,0), Invalid);
}

TEST(TicTacToeBoardTest, placePieceNegativeColumn)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(0,-1), Invalid);
}

TEST(TicTacToeBoardTest, getPieceNoPiece)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.getPiece(0,0), Blank);
}

TEST(TicTacToeBoardTest, getPieceOnePiece)
{
	TicTacToeBoard board;
	board.placePiece(0,0);
	ASSERT_EQ(board.getPiece(0,0), X);
}

TEST(TicTacToeBoardTest, getPieceTwoPieces)
{
	TicTacToeBoard board;
	board.placePiece(0,0);
	board.placePiece(0,1);
	ASSERT_EQ(board.getPiece(0,1), O);
}

TEST(TicTacToeBoardTest, getPieceNegativeColumn)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.getPiece(0, -1), Invalid);
}

TEST(TicTacToeBoardTest, getPieceNegativeRow)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.getPiece(-1, 0), Invalid);
}

TEST(TicTacToeBoardTest, getPieceInvalidColumn)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.getPiece(0, 3), Invalid);
}

TEST(TicTacToeBoardTest, getPieceInvalidRow)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.getPiece(3, 0), Invalid);
}

TEST(TicTacToeBoardTest, getPiecePiecePlacedButDifferentLocation)
{
	TicTacToeBoard board;
	board.placePiece(0,0);
	ASSERT_EQ(board.getPiece(0,1), Blank);
}

TEST(TicTacToeBoardTest, findWinnerFullBoardNoWinner)
{
	//x o x
	//o o x
	//x x o
	TicTacToeBoard board;

	board.placePiece(0,0);
	board.placePiece(0,1);
	board.placePiece(0,2);
	board.placePiece(1,0);
	board.placePiece(1,2);
	board.placePiece(1,1);
	board.placePiece(2,0);
	board.placePiece(2,2);
	board.placePiece(2,1);

	ASSERT_EQ(board.getWinner(), Blank);
}