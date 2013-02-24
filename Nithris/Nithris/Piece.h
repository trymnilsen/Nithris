//PG4400 - INNLEVERING 1 - TRYM NILSEN
#ifndef PIECE_H
#define PIECE_H

#include <array>
#include <memory>
#include "NithrisConstants.h"
#include "Position.h"

//Piece class is an abstract class used by all the pieces
//this class contains methods for manipulating the piece and the array storing the layout of it
//see boxPiece.h for explaination of innherited pieces
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
	void Transform(std::shared_ptr<Piece> transformTarget,EMovement movement);
	const std::array<std::array<bool,4>,4> getPieceArray() {return pieceObject;}
	virtual std::shared_ptr<Piece> CreateGhost(EMovement movement) = 0;
	Position piecePosition;
	ETileColor PieceColor;

protected:
	std::array<std::array<bool,4>,4> pieceObject;
};
#endif // !PIECE_H
