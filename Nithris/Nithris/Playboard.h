#ifndef PLAYBOARD_H
#define PLAYBOARD_H

#include "Piece.h"
#include "TileColor.h"
#include <vector>

class Playboard
{
public:
	const ETileColor colorOfTileAt(char collum, char row);
	bool setPieceAt(unsigned char collum,unsigned char row, Piece& piece);
	void checkBoard();
private:
	std::vector<std::vector<ETileColor>> boardVector;
};

#endif