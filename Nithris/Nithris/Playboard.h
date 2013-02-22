#ifndef PLAYBOARD_H
#define PLAYBOARD_H

#include "Piece.h"
#include "NithrisConstants.h"
#include <array>

class Playboard
{
public:
	Playboard();
	const ETileColor colorOfTileAt(int collum, int row);
	void setPieceAt(int collum,int row, Piece& piece);
	void checkBoard();
private:
	void initalizeBoard();
	std::array<std::array<ETileColor,playboardTilesHeight>,playboardTilesWidth> boardArray;
};

#endif