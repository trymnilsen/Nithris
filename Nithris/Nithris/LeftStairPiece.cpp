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

std::shared_ptr<Piece> LeftStairPiece::CreateGhost(EMovement movement)
{
	std::shared_ptr<Piece> ghost = std::shared_ptr<Piece>(new LeftStairPiece(*this));
	Piece::Transform(ghost,movement);
	return ghost;
}