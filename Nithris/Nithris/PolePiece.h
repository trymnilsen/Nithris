//PG4400 - INNLEVERING 1 - TRYM NILSEN
//see piece.h for explanation of the logic behind the pieces
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