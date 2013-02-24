//PG4400 - INNLEVERING 1 - TRYM NILSEN
#include "Piece.h"

Piece::Piece()
{
	//Creating a position for the piece to start at
	Position position;
	position.X=3;
	position.Y=0;
	piecePosition=position;
}

Piece::Piece(Piece& pieceClone)
{
	//constructor cloing, doing a deep copy of an object
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

void Piece::rotate()
{
	//rotates the piece given the algorithm in the assignment
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

void Piece::transform(std::shared_ptr<Piece> transformTarget,EMovement movement )
{
	//Chooses what to do with the piece based on the movement enum 
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




