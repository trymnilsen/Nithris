//PG4400 - INNLEVERING 1 - TRYM NILSEN
//see piece.h for explanation of the logic behind the pieces, this is only about the specialization
//we inherit the piece mainly because of showing that we can use inhertiance, but also so we can define different layouts
#ifndef BOXPIECE_H
#define BOXPIECE_H

#include "Piece.h"

class BoxPiece : public Piece
{
public:
	BoxPiece();
	//Creates a clone of a piece, this way we can easily create a new piece based on anotherone for example the ghostpiece
	BoxPiece(Piece& pieceClone):Piece(pieceClone){};
	//creates a ghost that is equal to this exact class..
	std::shared_ptr<Piece> createGhost(EMovement movement);
};
#endif // !BOXPIECE_H
