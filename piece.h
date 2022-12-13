#ifndef PIECE_H
#define PIECE_H

#include "includes.h"

class piece
{
public:

	string type; // p for pawn, k for knight, etc
	bool isWhite = false;
	int row = -1;
	int col = -1;
	void info();
};

#endif