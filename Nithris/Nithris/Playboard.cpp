#include "Playboard.h"

const ETileColor Playboard::colorOfTileAt( char collum, char row ) 
{
	const ETileColor returnColor = boardVector[collum][row];
	return returnColor;
}

bool Playboard::setPieceAt( unsigned char collum,unsigned char row, Piece& piece )
{
	return true;
}

void Playboard::checkBoard()
{

}

