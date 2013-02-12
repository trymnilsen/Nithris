#ifndef PLAYBOARD_H
#define PLAYBOARD_H

#include "Piece.h"
#include "TileColor.h"
#include <vector>

class Playboard
{
public:
	bool pieceAt(char collum, char row);
	bool setPieceAt(char collum, char row, Piece& piece);
	void checkBoard();
private:
	std::vector<std::vector<ETileColor>> boardVector;
};

#endif