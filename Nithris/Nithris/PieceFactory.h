//PG4400 - INNLEVERING 1 - TRYM NILSEN
#ifndef PIECEFACTORY_H
#define PIECEFACTORY_H

#include <array>
#include <memory>
#include <random>
#include <SDL.h>

#include "Piece.h"
//pieces
#include "BoxPiece.h"
#include "PolePiece.h"
#include "LeftStairPiece.h"
#include "LeftHookPiece.h"
#include "RightStairPiece.h"
#include "RightHookPiece.h"
#include "PolePiece.h"
#include "TPiece.h"

//Mayers Singleton piecefactoy generating a random piece
class PieceFactory
{
public:
	static PieceFactory& instance()
	{
		static PieceFactory gh;
		return gh;
	}
	//genereates and returns a shared_ptr to the random piece
	std::shared_ptr<Piece> generateRandomPiece();
private:
	PieceFactory(){};
	PieceFactory(const PieceFactory&);
	PieceFactory& operator=(const PieceFactory&);
};
#endif // !PIECEFACTORY_H
