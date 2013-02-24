#ifndef TPIECE_H
#define TPIECE_H

#include "Piece.h"

class TPiece : public Piece
{
public:
	TPiece();
	TPiece(Piece& pieceClone):Piece(pieceClone){};
	std::shared_ptr<Piece> CreateGhost(EMovement movement);
};
#endif TPIECE_H