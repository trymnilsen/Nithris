#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include "NithrisConstants.h"
#include "Position.h"

class Piece 
{
public:
	ETileColor& getColorAt(char x, char y);
	virtual void SetColorAt(const ETileColor&, char x, char y)=0;
	Position PiecePosition;

private:
	std::vector<std::vector<ETileColor>> pieceObject;
};
#endif // !PIECE_H
