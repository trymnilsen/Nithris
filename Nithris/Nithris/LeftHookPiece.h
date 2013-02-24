//PG4400 - INNLEVERING 1 - TRYM NILSEN
#ifndef LEFTHOOKPIECE_H
#define LEFTHOOKPIECE_H

#include "Piece.h"

class LeftHookPiece : public Piece
{
public:
	LeftHookPiece();
	LeftHookPiece(Piece& pieceClone):Piece(pieceClone){};
	std::shared_ptr<Piece> CreateGhost(EMovement movement);
};
#endif