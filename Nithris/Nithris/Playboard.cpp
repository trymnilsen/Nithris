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

bool Playboard::setPieceAt(int collum,int row, Piece& piece )
{
	return true;
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




