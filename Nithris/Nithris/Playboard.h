//PG4400 - INNLEVERING 1 - TRYM NILSEN
#ifndef PLAYBOARD_H
#define PLAYBOARD_H

#include "Piece.h"
#include "NithrisConstants.h"
#include <array>

class Playboard
{
public:
	Playboard();
	//gets the color at this position
	const ETileColor colorOfTileAt(int collum, int row);
	//Sets a piece at this position
	void setPieceAt(int collum,int row, Piece& piece);
	//Checks the board of complete lines, if this is the case the Movebricks down is called
	//and the method returns true which is used to increase speed and score
	short checkBoard();
	void moveBricksdown(short lineToRemove);
	//check if the game is over
	bool checkGameOver();

private:
	//Initialize board
	void initalizeBoard();
	std::array<std::array<ETileColor,PlayboardTilesHeight>,PlayboardTilesWidth> boardArray;
};

#endif