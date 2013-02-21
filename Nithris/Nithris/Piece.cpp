#include "Piece.h"

Piece::Piece()
{
	
	std::array<std::array<bool,4>,4> pieceLayout  = {
		0,0,0,0,
		0,0,1,1,
		0,1,1,0,
		0,0,0,0
	};
	pieceObject=pieceLayout;
}
bool Piece::tileAt(char x, char y )
{
	return pieceObject[x][y];
}

void Piece::setTileAt(char x, char y )
{

}



