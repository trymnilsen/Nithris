#include "TPiece.h"
TPiece::TPiece()
{
	std::array<std::array<bool,4>,4> pieceLayout  = {
		0,0,0,0,
		0,0,1,0,
		0,1,1,0,
		0,0,1,0
	};
	pieceObject=pieceLayout;
	PieceColor=TC_YELLOW;
}

std::shared_ptr<Piece> TPiece::CreateGhost(EMovement movement)
{
	std::shared_ptr<Piece> ghost = std::shared_ptr<Piece>(new TPiece(*this));
	Piece::Transform(ghost,movement);
	return ghost;
}