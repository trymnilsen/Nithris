#include "PieceFactory.h"
#include "BoxPiece.h"

std::shared_ptr<Piece> PieceFactory::GenerateRandomPiece()
{
	/*
	std::mt19937 mt;
	mt.seed(SDL_GetTicks());
	std::uniform_int_distribution<int> int_distributor(0,5);
	int num = int_distributor(mt);*/
	std::shared_ptr<Piece> returnPiece = std::shared_ptr<Piece>(new BoxPiece());
	return returnPiece;
}



