//PG4400 - INNLEVERING 1 - TRYM NILSEN
#include "Playboard.h"
//initalizes the board and the array
Playboard::Playboard()
{
	initalizeBoard();
}

//returns the color of the tile a position
const ETileColor Playboard::colorOfTileAt(int collum, int row ) 
{
	const ETileColor returnColor = boardArray[collum][row];
	return returnColor;
}
//sets the color at the pieces position in the playboard array
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
//checks the array for complete lines
short Playboard::checkBoard()
{
	short linesRemoved=0;
	//look through the lines 
	for(short y=0; y<playboardTilesHeight; ++y)
	{
		bool fullLine=false;
		//for each new line reset the full line
		for(short x=0; x<playboardTilesWidth; ++x)
		{
			if(boardArray[x][y]>0)
			{
				fullLine=true;
			}
			else
			{
				//a hole is found/the color is backgroundcolor
				//break out of the loop so we dont bug it up by removing a whole line because there was one tile at the end
				fullLine=false;
				break;
			}
		}
		if(fullLine)
		{
			//set the fact that a tile has been removed to true;
			++linesRemoved;
			moveBricksdown(y);
			//move the bricks down
		}
	}
	return linesRemoved;
	
}
//initilialize our board will all background
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
//move the bricks about the line down one notch.. notice how we start at the bottom and work our way up!
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
//check if the is a tile at the top
bool Playboard::checkGameOver()
{
	bool gameover=false;
	for(short x=0; x<playboardTilesWidth; x++)
	{
		if(boardArray[x][0]>0)
		{
			//if a tile is found we dont want to continue looking as we only need one to know its game over
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






