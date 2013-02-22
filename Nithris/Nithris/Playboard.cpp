#include "Playboard.h"

Playboard::Playboard()
{
	initalizeBoard();
}
const ETileColor Playboard::colorOfTileAt(int collum, int row ) 
{
	const ETileColor returnColor = boardArray[collum][row];
	return returnColor;
}

void Playboard::setPieceAt(int collum,int row, Piece& piece )
{
	for(int y=0; y<4; y++)
	{
		for(int x=0; x<4; x++)
		{
			if(piece.tileAt(x,y))
			boardArray[collum+x][row+y]=piece.PieceColor;
		}
	}
}

void Playboard::checkBoard()
{
	
}

void Playboard::initalizeBoard()
{
	for(int y=0; y<playboardTilesHeight; y++)
	{
		for (int x=0; x<playboardTilesWidth; x++)
		{
			boardArray[x][y]=TC_BACKGROUND;
		}
	}
}




