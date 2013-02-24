//PG4400 - INNLEVERING 1 - TRYM NILSEN
//see piece.h for explanation of the logic behind the pieces
#ifndef RIGHTHOOKPIECE_H
#define RIGHTHOOKPIECE_H

#include "Piece.h"

class RightHookPiece : public Piece
{
public:
	RightHookPiece();
	RightHookPiece(Piece& pieceClone):Piece(pieceClone){};
	std::shared_ptr<Piece> CreateGhost(EMovement movement);
};
#endif