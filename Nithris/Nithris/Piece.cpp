#include "Piece.h"

Piece::Piece()
{
	Position position;
	position.X=3;
	position.Y=0;
	piecePosition=position;
}

Piece::Piece(Piece& pieceClone)
{
	piecePosition=pieceClone.piecePosition;
	PieceColor=pieceClone.PieceColor;
	pieceObject=pieceClone.getPieceArray();
}

bool Piece::tileAt(int x, int y )
{
	return pieceObject[x][y];
}

void Piece::setTileAt(int x, int y )
{
	pieceObject[x][y]=1;
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


void Piece::rotate()
{
	std::array<std::array<bool,4>,4> newOrientation  = {
		0,0,0,0,
		0,0,0,0,
		0,0,0,0,
		0,0,0,0
	};
	for(int y=0; y<4; ++y)
	{
		for(int x=0; x<4; ++x)
		{
			if(tileAt(x,y))
			{
				newOrientation[3-y][x]=1;
			}
		}
	}
	pieceObject=newOrientation;
}

void Piece::Transform(std::shared_ptr<Piece> transformTarget,EMovement movement )
{
	switch (movement)
	{
	case EDIR_LEFT:
		transformTarget->piecePosition.X=transformTarget->piecePosition.X-1;
		break;
	case EDIR_RIGHT:
		transformTarget->piecePosition.X=transformTarget->piecePosition.X+1;
		break;
	case EDIR_ROTATE:
		transformTarget->rotate();
		break;
	case EDIR_DROP:
		transformTarget->piecePosition.Y=transformTarget->piecePosition.Y+1;
		break;
	default:
		break;
	}
}



