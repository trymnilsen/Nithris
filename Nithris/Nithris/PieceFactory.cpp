//PG4400 - INNLEVERING 1 - TRYM NILSEN
#include "PieceFactory.h"

std::shared_ptr<Piece> PieceFactory::generateRandomPiece()
{
	//generate random number between 0 and 6 giving us different pieces and return a shared pointers to it
	std::random_device generator;
	std::uniform_int_distribution<int> int_distributor(0,6);
	int num = int_distributor(generator);
	std::shared_ptr<Piece> returnPiece;
	switch (num)
	{
	case 0:
		returnPiece = std::shared_ptr<Piece>(new BoxPiece());
		break;
	case 1:
		returnPiece = std::shared_ptr<Piece>(new LeftStairPiece());
		break;
	case 2:
		returnPiece = std::shared_ptr<Piece>(new RightStairPiece());
		break;
	case 3:
		returnPiece = std::shared_ptr<Piece>(new TPiece());
		break;
	case 4:
		returnPiece = std::shared_ptr<Piece>(new LeftHookPiece());
		break;
	case 5:
		returnPiece = std::shared_ptr<Piece>(new RightHookPiece());
		break;
	case 6:
		returnPiece = std::shared_ptr<Piece>(new PolePiece());
		break;
	default:
		break;
	}
	
	return returnPiece;
}



