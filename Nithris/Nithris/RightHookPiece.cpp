//PG4400 - INNLEVERING 1 - TRYM NILSEN
#include "RightHookPiece.h"
RightHookPiece::RightHookPiece()
{
	std::array<std::array<bool,4>,4> pieceLayout  = {
		0,0,0,0,
		1,1,1,0,
		0,0,1,0,
		0,0,0,0
	};
	pieceObject=pieceLayout;
	PieceColor=TC_YELLOW;
}

std::shared_ptr<Piece> RightHookPiece::createGhost(EMovement movement)
{
	std::shared_ptr<Piece> ghost = std::shared_ptr<Piece>(new RightHookPiece(*this));
	Piece::transform(ghost,movement);
	return ghost;
}