#include "Round.h"
#include "PieceFactory.h"

Round::Round()
{
	gamePlayboard.swap(std::shared_ptr<Playboard>(new Playboard()));
	nextPiece=PieceFactory::instance().GenerateRandomPiece();
	CurrentPiece=PieceFactory::instance().GenerateRandomPiece();
	score=0;
	dropSpeed=StartDropSpeed;
}

void Round::generateNextPiece()
{
	nextPiece=PieceFactory::instance().GenerateRandomPiece();
}

std::shared_ptr<Piece> Round::getCurrentPiece()
{
	return CurrentPiece;
}

std::shared_ptr<Playboard> Round::getPlayboard()
{
	return gamePlayboard;
}

std::shared_ptr<Piece> Round::getNextPiece()
{
	std::shared_ptr<Piece> returnPiece = nextPiece;
	return returnPiece;
}

void Round::setCurrentPiece(std::shared_ptr<Piece> pieceToSet)
{
	CurrentPiece = pieceToSet;
}



