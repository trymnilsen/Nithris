//PG4400 - INNLEVERING 1 - TRYM NILSEN
#include "Round.h"
#include "PieceFactory.h"

//constructor for the round creating the playboard and needed pieces
Round::Round()
{
	gamePlayboard.swap(std::shared_ptr<Playboard>(new Playboard()));
	nextPiece=PieceFactory::instance().GenerateRandomPiece();
	CurrentPiece=PieceFactory::instance().GenerateRandomPiece();
	score=0;
	dropSpeed=StartDropSpeed;
}
//asks the piecefactory for a new piece
void Round::generateNextPiece()
{
	nextPiece=PieceFactory::instance().GenerateRandomPiece();
}
//returns the current piece
std::shared_ptr<Piece> Round::getCurrentPiece()
{
	return CurrentPiece;
}
//returns the playboard
std::shared_ptr<Playboard> Round::getPlayboard()
{
	return gamePlayboard;
}
//gets the next piece
std::shared_ptr<Piece> Round::getNextPiece()
{
	return nextPiece;
}
//sets the currentPiece
void Round::setCurrentPiece(std::shared_ptr<Piece> pieceToSet)
{
	CurrentPiece = pieceToSet;
}



