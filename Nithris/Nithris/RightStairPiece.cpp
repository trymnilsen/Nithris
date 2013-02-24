//PG4400 - INNLEVERING 1 - TRYM NILSEN
#include "RightStairPiece.h"
RightStairPiece::RightStairPiece()
{
	std::array<std::array<bool,4>,4> pieceLayout  = {
		0,0,0,0,
		0,1,0,0,
		0,1,1,0,
		0,0,1,0
	};
	pieceObject=pieceLayout;
	PieceColor=TC_GREEN;
}

std::shared_ptr<Piece> RightStairPiece::CreateGhost(EMovement movement)
{
	std::shared_ptr<Piece> ghost = std::shared_ptr<Piece>(new RightStairPiece(*this));
	Piece::Transform(ghost,movement);
	return ghost;
}