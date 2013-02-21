#include "Playboard.h"

Playboard::Playboard()
{
	//initalizeBoard();
}
const ETileColor Playboard::colorOfTileAt(char collum, char row ) 
{
	const ETileColor returnColor = boardArray[collum][row];
	return returnColor;
}

bool Playboard::setPieceAt(unsigned char collum,unsigned char row, Piece& piece )
{
	return true;
}

void Playboard::checkBoard()
{
	
}

void Playboard::initalizeBoard()
{
	for(char y=0; y<playboardTilesHeight; y++)
	{
		for (char x=0; x<PlayboardPixelsWidth; x++)
		{
			boardArray[x][y]=TC_BACKGROUND;
		}
	}
}




