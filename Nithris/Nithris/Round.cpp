#include "Round.h"
#include "PieceFactory.h"

Round::Round()
{
	gamePlayboard.swap(std::shared_ptr<Playboard>(new Playboard()));
	nextPiece=PieceFactory::instance().GenerateRandomPiece();
	CurrentPiece=PieceFactory::instance().GenerateRandomPiece();
	score=0;
}

void Round::generateNextPiece()
{
	
}

std::shared_ptr<Piece> Round::getCurrentPiece()
{
	return CurrentPiece;
}

std::shared_ptr<Playboard> Round::getPlayboard()
{
	return gamePlayboard;
}

Piece& Round::getNextPiece()
{
	return *nextPiece.get();
}

void Round::setCurrentPiece(std::shared_ptr<Piece> pieceToSet)
{
	CurrentPiece = pieceToSet;
}


