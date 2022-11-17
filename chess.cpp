#include "chess.h"

// -------------------------------------------------------------------
// Chess class
// -------------------------------------------------------------------
int Chess::getPieceColor(char chPiece)
{
    if (isupper(chPiece))
    {
        return WHITE_PIECE;
    }
    else
    {
        return BLACK_PIECE;
    }
}

bool Chess::isWhitePiece(char chPiece)
{
    return getPieceColor(chPiece) == Chess::WHITE_PIECE ? true : false;
}

bool Chess::isBlackPiece(char chPiece)
{
    return getPieceColor(chPiece) == Chess::BLACK_PIECE ? true : false;
}

std::string Chess::describePiece(char chPiece)
{
    std::string description;

    if (isWhitePiece(chPiece))
    {
        description += "White ";
    }
    else
    {
        description += "Black ";
    }

    switch (toupper(chPiece))
    {
    case 'P':
    {
        description += "pawn";
    }
    break;

    case 'N':
    {
        description += "knight";
    }
    break;

    case 'B':
    {
        description += "bishop";
    }
    break;

    case 'R':
    {
        description += "rook";
    }
    break;

    case 'Q':
    {
        description += "queen";
    }
    break;

    default:
    {
        description += "unknow piece";
    }
    break;
    }

    return description;
}

void Chess::printLogo(void)
{
    cout << "    ======================================\n";
    cout << "       _____ _    _ ______  _____ _____\n";
    cout << "      / ____| |  | |  ____|/ ____/ ____|\n";
    cout << "     | |    | |__| | |__  | (___| (___ \n";
    cout << "     | |    |  __  |  __|  \\___ \\\\___ \\ \n";
    cout << "     | |____| |  | | |____ ____) |___) |\n";
    cout << "      \\_____|_|  |_|______|_____/_____/\n\n";
    cout << "    ======================================\n\n";
}

char Chess::getPieceAtPosition(int iRow, int iColumn)
{
    return board[iRow][iColumn];
}

void Chess::printLine(int iLine, int iColor1, int iColor2)
{
    // Example (for CELL = 6):

    //  [6-char]
    //  |______| subline 1
    //  |___Q__| subline 2
    //  |______| subline 3

    // Define the CELL variable here. 
    // It represents how many horizontal characters will form one square
    // The number of vertical characters will be CELL/2
    // You can change it to alter the size of the board (an odd number will make the squares look rectangular)
    int CELL = 6;

    // Since the width of the characters BLACK and WHITE is half of the height,
    // we need to use two characters in a row.
    // So if we have CELL characters, we must have CELL/2 sublines
    for (int subLine = 0; subLine < CELL / 2; subLine++)
    {
        // A sub-line is consisted of 8 cells, but we can group it
        // in 4 iPairs of black&white
        for (int iPair = 0; iPair < 4; iPair++)
        {
            // First cell of the pair
            for (int subColumn = 0; subColumn < CELL; subColumn++)
            {
                // The piece should be in the "middle" of the cell
                // For 3 sub-lines, in sub-line 1
                // For 6 sub-columns, sub-column 3
                if (subLine == 1 && subColumn == 3)
                {
                    cout << char(getPieceAtPosition(iLine, iPair * 2) != 0x20 ? getPieceAtPosition(iLine, iPair * 2) : iColor1);
                }
                else
                {
                    cout << char(iColor1);
                }
            }

            // Second cell of the pair
            for (int subColumn = 0; subColumn < CELL; subColumn++)
            {
                // The piece should be in the "middle" of the cell
                // For 3 sub-lines, in sub-line 1
                // For 6 sub-columns, sub-column 3
                if (subLine == 1 && subColumn == 3)
                {
                    cout << char(getPieceAtPosition(iLine, iPair * 2 + 1) != 0x20 ? getPieceAtPosition(iLine, iPair * 2 + 1) : iColor2);
                }
                else
                {
                    cout << char(iColor2);
                }
            }
        }

        // Write the number of the line on the right
        if (1 == subLine)
        {
            cout << "   " << iLine + 1;
        }

        cout << "\n";

    }
}

void Chess::printBoard()
{
    cout << "   A     B     C     D     E     F     G     H\n\n";

    for (int iLine = 7; iLine >= 0; iLine--)
    {
        if (iLine % 2 == 0)
        {
            // Line starting with BLACK
            printLine(iLine, BLACK_SQUARE, WHITE_SQUARE);
        }

        else
        {
            // Line starting with WHITE
            printLine(iLine, WHITE_SQUARE, BLACK_SQUARE);
        }
    }
}

void Chess::printEmptyBoard(void)
{
    int CELL = 8;

    for (int i = 0; i < 8; i++)
    {
        // Line starting with WHITE
        if (i % 2 == 0)
        {
            for (int z = 0; z < CELL / 2; z++)
            {
                cout << "   ";
                for (int w = 0; w < 4; w++)
                {
                    for (int j = 0; j < CELL; j++)
                    {
                        cout << char(0xDB);
                    }

                    for (int j = 0; j < CELL; j++)
                    {
                        cout << char(0xFF);
                    }
                }
                cout << "\n";
            }
        }
        // Line starting with BLACK
        else
        {
            for (int z = 0; z < CELL / 2; z++)
            {
                cout << "   ";
                for (int w = 0; w < 4; w++)
                {
                    for (int j = 0; j < CELL; j++)
                    {
                        cout << char(0xFF);
                    }

                    for (int j = 0; j < CELL; j++)
                    {
                        cout << char(0xDB);
                    }
                }
                cout << "\n";
            }
        }
    }
}


