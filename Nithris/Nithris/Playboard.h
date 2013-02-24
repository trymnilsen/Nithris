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
	void setPieceAt(int collum,int row, Piece& piece);
	bool checkBoard();
	bool checkGameOver();
	void moveBricksdown(short lineToRemove);
private:
	void initalizeBoard();
	std::array<std::array<ETileColor,playboardTilesHeight>,playboardTilesWidth> boardArray;
};

#endif