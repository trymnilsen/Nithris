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
	void getCurrentPiece();
	std::shared_ptr<Playboard> getPlayboard();
	//Constant reference as we never need to be able to change this, just know it
	Piece& getNextPiece();

private:
	std::shared_ptr<Playboard> gamePlayboard;
	std::unique_ptr<Piece> nextPiece;
	int score;
};
#endif