#include "board.h"

board::board()
{
	pieces[0] = piece();
	pieces[0].type = "T";
	pieces[0].isWhite = true;
	pieces[0].row = 0;
	pieces[0].col = 0;

	pieces[1] = piece();
	pieces[1].type = "N";
	pieces[1].isWhite = true;
	pieces[1].row = 0;
	pieces[1].col = 1;

	pieces[2] = piece();
	pieces[2].type = "B";
	pieces[2].isWhite = true;
	pieces[2].row = 0;
	pieces[2].col = 2;

	pieces[3] = piece();
	pieces[3].type = "Q";
	pieces[3].isWhite = true;
	pieces[3].row = 0;
	pieces[3].col = 3;

	pieces[4] = piece();
	pieces[4].type = "K";
	pieces[4].isWhite = true;
	pieces[4].row = 0;
	pieces[4].col = 4;

	pieces[5] = piece();
	pieces[5].type = "B";
	pieces[5].isWhite = true;
	pieces[5].row = 0;
	pieces[5].col = 5;

	pieces[6] = piece();
	pieces[6].type = "N";
	pieces[6].isWhite = true;
	pieces[6].row = 0;
	pieces[6].col = 6;

	pieces[7] = piece();
	pieces[7].type = "T";
	pieces[7].isWhite = true;
	pieces[7].row = 0;
	pieces[7].col = 7;

	for (int i = 8; i < 16; i++)
	{
		pieces[i] = piece();
		pieces[i].type = "P";
		pieces[i].isWhite = true;
		pieces[i].row = 1;
		pieces[i].col = i - 8;
	}

	for (int i = 16; i < 24; i++)
	{
		pieces[i] = piece();
		pieces[i].type = "p";
		pieces[i].isWhite = false;
		pieces[i].row = 6;
		pieces[i].col = i - 16;
	}

	pieces[24] = piece();
	pieces[24].type = "t";
	pieces[24].isWhite = false;
	pieces[24].row = 7;
	pieces[24].col = 0;

	pieces[25] = piece();
	pieces[25].type = "n";
	pieces[25].isWhite = false;
	pieces[25].row = 7;
	pieces[25].col = 1;

	pieces[26] = piece();
	pieces[26].type = "b";
	pieces[26].isWhite = false;
	pieces[26].row = 7;
	pieces[26].col = 2;

	pieces[27] = piece();
	pieces[27].type = "q";
	pieces[27].isWhite = false;
	pieces[27].row = 7;
	pieces[27].col = 3;

	pieces[28] = piece();
	pieces[28].type = "k";
	pieces[28].isWhite = false;
	pieces[28].row = 7;
	pieces[28].col = 4;

	pieces[29] = piece();
	pieces[29].type = "b";
	pieces[29].isWhite = false;
	pieces[29].row = 7;
	pieces[29].col = 5;

	pieces[30] = piece();
	pieces[30].type = "n";
	pieces[30].isWhite = false;
	pieces[30].row = 7;
	pieces[30].col = 6;

	pieces[31] = piece();
	pieces[31].type = "t";
	pieces[31].isWhite = false;
	pieces[31].row = 7;
	pieces[31].col = 7;
}

string board::printOnWhite(string a)
{
	return "\033[47;30m " + a + " \033[0m";
}

string board::printOnBlack(string a)
{
	return " " + a + " ";
}

void board::printBoard()
{
	// DEBUGGING FOR PRINTING ALL PIECES
	// for (int i = 0; i < NUMBER_PIECES; i++)
	// {
	// 	pieces[i].info();
	// }

	cout << " A  B  C  D  E  F  G  H " << endl;
	for (int y = 0; y < BOARD_SIZE; y++)
	{
		for (int x = 0; x < BOARD_SIZE; x++)
		{
			if (y % 2 == 0)
			{
				string typeOfPiece = getSquareType(y, x);

				if (x % 2 == 0)
				{

					cout << printOnWhite(typeOfPiece);
				}
				else
				{
					cout << printOnBlack(typeOfPiece);
				}
			}
			else
			{

				string typeOfPiece = getSquareType(y, x);

				if (x % 2 != 0)
				{
					cout << printOnWhite(typeOfPiece);
				}
				else
				{
					cout << printOnBlack(typeOfPiece);
				}
			}
		}
		cout << " " << y + 1;
		cout << endl;
	}
}

string board::getSquareType(int row, int col)
{
	for (int i = 0; i < NUMBER_PIECES; i++)
	{
		piece p = pieces[i];
		if (p.row == row && p.col == col)
		{
			return p.type;
		}
	}

	return " ";
}