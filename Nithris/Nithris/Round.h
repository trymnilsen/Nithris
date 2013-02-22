#ifndef ROUND_H
#define ROUND_H

#include"Playboard.h"
#include"Piece.h"
#include <memory>

class Round
{
public:
	Round();
	void generateNextPiece();
	std::shared_ptr<Piece> getCurrentPiece();
	std::shared_ptr<Playboard> getPlayboard();
	void setCurrentPiece(std::shared_ptr<Piece> pieceToSet);
	Piece& getNextPiece();
	int score;

private:
	std::shared_ptr<Playboard> gamePlayboard;
	std::shared_ptr<Piece> nextPiece;
	std::shared_ptr<Piece> CurrentPiece;

};
#endif