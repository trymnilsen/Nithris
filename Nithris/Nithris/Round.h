#ifndef ROUND_H
#define ROUND_H

#include"Playboard.h"
#include"Piece.h"
#include <memory>

class Round
{
public:
	void generateNextPiece();
	void getCurrentPiece();
	std::shared_ptr<Playboard> getPlayboard();

private:
	std::shared_ptr<Playboard> gamePlayboard;
	std::unique_ptr<Piece> nextPiece;
	int score;
};
#endif