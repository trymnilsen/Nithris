#ifndef BOXPIECE_H
#define BOXPIECE_H

#include "Piece.h"

class BoxPiece : public Piece
{
public:
	BoxPiece();
	BoxPiece(Piece& pieceClone):Piece(pieceClone){};
	std::shared_ptr<Piece> CreateGhost(EMovement movement);
};
#endif // !BOXPIECE_H
