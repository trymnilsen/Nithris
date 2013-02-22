#ifndef PIECE_H
#define PIECE_H

#include <array>
#include <memory>
#include "NithrisConstants.h"
#include "Position.h"


class Piece 
{
public:
	Piece();
	Piece(Piece& pieceClone);
	bool tileAt(int x, int y);
	void setTileAt(int x, int y);
	void nudge(char tiles);
	void dropOne();
	void dropDown(char NumberOfTiles);
	void rotate();
	const std::array<std::array<bool,4>,4> getPieceArray() {return pieceObject;}
	std::shared_ptr<Piece> CreateGhost(EMovement movement);
	Position piecePosition;
	ETileColor PieceColor;

private:
	std::array<std::array<bool,4>,4> pieceObject;
};
#endif // !PIECE_H
