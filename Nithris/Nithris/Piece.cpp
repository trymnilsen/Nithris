#include "Piece.h"

ETileColor& Piece::getColorAt( char x, char y )
{
	return pieceObject[x][y];
}

void Piece::SetColorAt( const ETileColor&, char x, char y )
{

}

