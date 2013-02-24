//PG4400 - INNLEVERING 1 - TRYM NILSEN
#include "BoxPiece.h"
BoxPiece::BoxPiece()
{
	//the array of our pieces deiciding how it looks
	std::array<std::array<bool,4>,4> pieceLayout  = {
		0,0,0,0,
		0,1,1,0,
		0,1,1,0,
		0,0,0,0
	};
	pieceObject=pieceLayout;
	PieceColor=TC_BLUE;
}

std::shared_ptr<Piece> BoxPiece::createGhost(EMovement movement)
{
	//creates an instance of this, giving us the correct array and does a call to the baseclass
	//decreasing the amount of code we need in each piecefile
	std::shared_ptr<Piece> ghost = std::shared_ptr<Piece>(new BoxPiece(*this));
	Piece::transform(ghost,movement);
	return ghost;
}


