//PG4400 - INNLEVERING 1 - TRYM NILSEN
#include "LeftStairPiece.h"
LeftStairPiece::LeftStairPiece()
{
	std::array<std::array<bool,4>,4> pieceLayout  = {
		0,0,0,0,
		0,0,1,0,
		0,1,1,0,
		0,1,0,0
	};
	pieceObject=pieceLayout;
	PieceColor=TC_CYAN;
}

std::shared_ptr<Piece> LeftStairPiece::createGhost(EMovement movement)
{
	std::shared_ptr<Piece> ghost = std::shared_ptr<Piece>(new LeftStairPiece(*this));
	Piece::transform(ghost,movement);
	return ghost;
}