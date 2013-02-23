#ifndef PIECEFACTORY_H
#define PIECEFACTORY_H

#include <array>
#include <memory>
#include <random>
#include <SDL.h>

#include "Piece.h"


class PieceFactory
{
public:
	static PieceFactory& instance()
	{
		static PieceFactory gh;
		return gh;
	}
	std::shared_ptr<Piece> GenerateRandomPiece();
private:
	PieceFactory(){};
	PieceFactory(const PieceFactory&);
	PieceFactory& operator=(const PieceFactory&);
	
	/*std::array<std::array<std::array<bool,4>,4>,7> pieces;
	{{
		{
			{0,0,0,0}
			{0,1,1,0}
			{0,1,1,0}
			{0,0,0,0}
		}//,*/
		/*{
			0,0,0,0,
			0,0,1,0,
			0,1,1,0,
			0,1,0,0
		},
		{
			0,0,0,0,
			0,1,0,0,
			0,1,1,0,
			0,0,1,0
		},
		{
			0,0,0,0,
			0,0,1,0,
			0,1,1,0,
			0,0,1,0
		},
		{
			0,0,0,0,
			0,0,0,0,
			1,1,1,1,
			0,0,0,0
		},
		{
			0,0,0,0,
			0,1,0,0,
			0,1,1,1,
			0,0,0,0
		},
		{
			0,0,0,0,
			0,1,1,1,
			0,1,0,0,
			0,0,0,0
		}
	}};*/
};
#endif // !PIECEFACTORY_H
