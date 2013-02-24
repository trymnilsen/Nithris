#ifndef POSITION_H
#define POSITION_H
class Position
{
public:
	Position operator+(Position otherPosition);
	Position operator-(Position otherPosition);
	void operator=(Position otherPosition);
	int X;
	int Y;
};
#endif