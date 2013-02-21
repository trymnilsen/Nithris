#include "Round.h"

Round::Round()
{
	gamePlayboard.swap(std::shared_ptr<Playboard>(new Playboard()));
	nextPiece=std::unique_ptr<Piece>(new Piece());
	score=0;
}

void Round::generateNextPiece()
{
	
}

void Round::getCurrentPiece()
{
	
}

std::shared_ptr<Playboard> Round::getPlayboard()
{
	return gamePlayboard;
}

Piece& Round::getNextPiece()
{
	return *nextPiece.get();
}


