#include "BoxPiece.h"
BoxPiece::BoxPiece()
{
	std::array<std::array<bool,4>,4> pieceLayout  = {
		0,0,0,0,
		0,1,1,0,
		0,1,1,0,
		0,0,0,0
	};
	pieceObject=pieceLayout;
	PieceColor=TC_BLUE;
}

std::shared_ptr<Piece> BoxPiece::CreateGhost(EMovement movement)
{
	std::shared_ptr<Piece> ghost = std::shared_ptr<Piece>(new BoxPiece(*this));
	Piece::Transform(ghost,movement);
	return ghost;
}

