#include "Position.h"
Position Position::operator+( Position otherPosition )
{
	Position temp;
	temp.X=X+otherPosition.X;
	temp.Y=Y+otherPosition.Y;
	return temp;
}

Position Position::operator-( Position otherPosition )
{
	Position temp;
	temp.X=X-otherPosition.X;
	temp.Y=Y-otherPosition.Y;
	return temp;
}

void Position::operator=( Position otherPosition )
{
	X=otherPosition.X;
	Y=otherPosition.Y;
}

