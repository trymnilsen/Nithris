#ifndef POLEPIECE_H
#define POLEPIECE_H

#include "Piece.h"

class PolePiece : public Piece
{
public:
	PolePiece();
	PolePiece(Piece& pieceClone):Piece(pieceClone){};
	std::shared_ptr<Piece> CreateGhost(EMovement movement);
};
#endif