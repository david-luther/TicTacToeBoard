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