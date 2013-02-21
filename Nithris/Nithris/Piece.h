#ifndef PIECE_H
#define PIECE_H

#include <array>
#include "NithrisConstants.h"
#include "Position.h"

class Piece 
{
public:
	Piece();
	bool tileAt(char x, char y);
	void setTileAt(char x, char y);
	Position PiecePosition;
	ETileColor PieceColor;

private:
	std::array<std::array<bool,4>,4> pieceObject;
};
#endif // !PIECE_H
