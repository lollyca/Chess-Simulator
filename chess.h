#ifndef CHESS_H
#define CHESS_H

#include "includes.h"

class Chess
{
public:
	int getPieceColor(char chPiece);

	bool isWhitePiece(char chPiece);

	bool isBlackPiece(char chPiece);

	std::string describePiece(char chPiece);

	void printLogo(void);

	void printBoard();

	void printLine(int iLine, int iColor1, int iColor2);

	char getPieceAtPosition(int iRow, int iColumn);

	void printEmptyBoard(void);

	enum PieceColor
	{
		WHITE_PIECE = 0,
		BLACK_PIECE = 1
	};

	enum Player
	{
		WHITE_PLAYER = 0,
		BLACK_PLAYER = 1
	};

	enum Side
	{
		QUEEN_SIDE = 2,
		KING_SIDE = 3
	};

	enum Direction
	{
		HORIZONTAL = 0,
		VERTICAL,
		DIAGONAL,
		L_SHAPE
	};

	struct Position
	{
		int iRow;
		int iColumn;
	};


	const char initial_board[8][8] =
	{
		// This represents the pieces on the board.
		// Keep in mind that pieces[0][0] represents A1
		// pieces[1][1] represents B2 and so on.
		// Letters in CAPITAL are white
		{ 'R',  'N',  'B',  'Q',  'K',  'B',  'N',  'R' },
		{ 'P',  'P',  'P',  'P',  'P',  'P',  'P',  'P' },
		{ 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
		{ 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
		{ 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
		{ 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
		{ 'p',  'p',  'p',  'p',  'p',  'p',  'p',  'p' },
		{ 'r',  'n',  'b',  'q',  'k',  'b',  'n',  'r' },
	};

private:

	// Represent the pieces in the board
	char board[8][8];
};
#endif

