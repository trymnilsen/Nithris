//PG4400 - INNLEVERING 1 - TRYM NILSEN
#include "LeftHookPiece.h"
LeftHookPiece::LeftHookPiece()
{
	std::array<std::array<bool,4>,4> pieceLayout  = {
		0,0,0,0,
		0,0,1,0,
		1,1,1,0,
		0,0,0,0
	};
	pieceObject=pieceLayout;
	PieceColor=TC_ORANGE;
}

std::shared_ptr<Piece> LeftHookPiece::CreateGhost(EMovement movement)
{
	std::shared_ptr<Piece> ghost = std::shared_ptr<Piece>(new LeftHookPiece(*this));
	Piece::Transform(ghost,movement);
	return ghost;
}