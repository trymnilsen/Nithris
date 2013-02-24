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