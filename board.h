#ifndef BOARD_H
#define BOARD_H

#include "includes.h"
#include "piece.h"


class board
{
public:
 	static const int BOARD_SIZE = 8;
 	static const int NUMBER_PIECES = 32;

	piece pieces[NUMBER_PIECES];

	string printOnWhite(string a);
	string printOnBlack(string a);
	void printBoard();
	string getSquareType(int row, int col);
	board();
};
#endif
