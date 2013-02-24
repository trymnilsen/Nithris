//PG4400 - INNLEVERING 1 - TRYM NILSEN
#include "PolePiece.h"
PolePiece::PolePiece()
{
	std::array<std::array<bool,4>,4> pieceLayout  = {
		0,0,0,0,
		0,0,0,0,
		1,1,1,1,
		0,0,0,0
	};
	pieceObject=pieceLayout;
	PieceColor=TC_RED;
}

std::shared_ptr<Piece> PolePiece::CreateGhost(EMovement movement)
{
	std::shared_ptr<Piece> ghost = std::shared_ptr<Piece>(new PolePiece(*this));
	Piece::Transform(ghost,movement);
	return ghost;
}