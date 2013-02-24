#ifndef LEFTSTAIRPIECE_H
#define LEFTSTAIRPIECE_H

#include "Piece.h"

class LeftStairPiece : public Piece
{
public:
	LeftStairPiece();
	LeftStairPiece(Piece& pieceClone):Piece(pieceClone){};
	std::shared_ptr<Piece> CreateGhost(EMovement movement);
};
#endif