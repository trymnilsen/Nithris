#ifndef PIECE_H
#define PIECE_H

#include <array>
#include "NithrisConstants.h"
#include "Position.h"

class Piece 
{
public:
	Piece();
	bool tileAt(int x, int y);
	void setTileAt(int x, int y);
	Position PiecePosition;
	ETileColor PieceColor;

private:
	std::array<std::array<bool,4>,4> pieceObject;
};
#endif // !PIECE_H
