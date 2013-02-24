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

bool Playboard::checkBoard()
{
	bool hasLinesBeenRemoved=false;
	for(short y=0; y<playboardTilesHeight; ++y)
	{
		bool fullLine=false;
		for(short x=0; x<playboardTilesWidth; ++x)
		{
			if(boardArray[x][y]>0)
			{
				fullLine=true;
			}
			else
			{
				fullLine=false;
				break;
			}
		}
		if(fullLine)
		{
			hasLinesBeenRemoved=true;
			moveBricksdown(y);
		}
	}
	return hasLinesBeenRemoved;
	
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

void Playboard::moveBricksdown(short lineToRemove)
{
	for(short y=lineToRemove; y>0; --y)
	{
		for(short x=0; x<playboardTilesWidth; ++x)
		{
			boardArray[x][y]=boardArray[x][y-1];
		}
	}
}

bool Playboard::checkGameOver()
{
	bool gameover=false;
	for(short x=0; x<playboardTilesWidth; x++)
	{
		if(boardArray[x][0]>0)
		{
			gameover=true;
			break;
		}
		else
		{
			gameover=false;
		}
	}
	return gameover;
}




