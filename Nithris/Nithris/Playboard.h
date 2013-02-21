#ifndef PLAYBOARD_H
#define PLAYBOARD_H

#include "Piece.h"
#include "NithrisConstants.h"
#include <array>

class Playboard
{
public:
	Playboard();
	const ETileColor colorOfTileAt(char collum, char row);
	bool setPieceAt(unsigned char collum,unsigned char row, Piece& piece);
	void checkBoard();
private:
	void initalizeBoard();
	std::array<std::array<ETileColor,playboardTilesWidth>,playboardTilesHeight> boardArray;
};

#endif