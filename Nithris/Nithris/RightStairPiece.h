#ifndef RIGHTSTAIRPIECE_H
#define RIGHTSTAIRPIECE_H

#include "Piece.h"

class RightStairPiece : public Piece
{
public:
	RightStairPiece();
	RightStairPiece(Piece& pieceClone):Piece(pieceClone){};
	std::shared_ptr<Piece> CreateGhost(EMovement movement);
};

#endif
