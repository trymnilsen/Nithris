//PG4400 - INNLEVERING 1 - TRYM NILSEN
//see piece.h for explanation of the logic behind the pieces
#ifndef RIGHTSTAIRPIECE_H
#define RIGHTSTAIRPIECE_H

#include "Piece.h"

class RightStairPiece : public Piece
{
public:
	RightStairPiece();
	RightStairPiece(Piece& pieceClone):Piece(pieceClone){};
	std::shared_ptr<Piece> createGhost(EMovement movement);
};

#endif
