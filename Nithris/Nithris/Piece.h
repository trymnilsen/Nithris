#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include "TileColor.h"
#include "Position.h"

class Piece 
{
public:
	std::vector<std::vector<ETileColor>> pieceObject;
	Position PiecePosition;

private:
	
};
#endif // !PIECE_H
