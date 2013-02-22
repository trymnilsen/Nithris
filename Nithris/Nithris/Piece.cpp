#include "Piece.h"

Piece::Piece()
{
	
	std::array<std::array<bool,4>,4> pieceLayout  = {
		0,0,0,0,
		1,1,0,0,
		1,0,0,0,
		0,0,0,0
	};
	pieceObject=pieceLayout;
	PieceColor=TC_GREEN;
	Position position;
	position.X=3;
	position.Y=1;
	piecePosition=position;
}
bool Piece::tileAt(int x, int y )
{
	return pieceObject[x][y];
}

void Piece::setTileAt(int x, int y )
{

}

void Piece::nudge(char tiles)
{
	Position newPosition;
	newPosition.X=piecePosition.X+tiles;
	newPosition.Y=piecePosition.Y;
	piecePosition=newPosition;
}

void Piece::dropOne()
{
	Position newPosition;
	newPosition.X=piecePosition.X;
	newPosition.Y=piecePosition.Y+1;
	piecePosition=newPosition;
}

void Piece::dropDown(char numberOfTiles)
{
		Position newPosition;
		newPosition.X=piecePosition.X;
		newPosition.Y=piecePosition.Y+numberOfTiles;
		piecePosition=newPosition;
}

std::shared_ptr<Piece> Piece::CreateGhost(EMovement movement)
{
	std::shared_ptr<Piece> ghost = std::shared_ptr<Piece>(new Piece());
	Position ghostPos;
	switch (movement)
	{
	case EDIR_LEFT:
		ghostPos.X=piecePosition.X-1;
		ghostPos.Y=piecePosition.Y;
		ghost->piecePosition=ghostPos;
		break;
	case EDIR_RIGHT:
		ghostPos.X=piecePosition.X+1;
		ghostPos.Y=piecePosition.Y;
		ghost->piecePosition=ghostPos;
		break;
	case EDIR_ROTATE:
		break;
	case EDIR_DROP:
		ghostPos.X=piecePosition.X;
		ghostPos.Y=piecePosition.Y+1;
		ghost->piecePosition=ghostPos;
		break;
	default:
		break;
	}
	return ghost;
}



