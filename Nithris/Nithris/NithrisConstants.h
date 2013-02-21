#ifndef NITHRISCONSTANTS_H
#define NITHRISCONSTANTS_H

enum ETileColor
{
	TC_NO_DRAW = -1,
	TC_BACKGROUND,
	TC_ORANGE,
	TC_RED,
	TC_GREEN,
	TC_BLUE,
	TC_CYAN,
	TC_MAGENTA,
	TC_YELLOW
};
enum EPromtType
{
	PROMT_NEWGAME,
	PROMT_PAUSE,
	PROMT_GAMEOVER
};
enum EDirection
{
	EDIR_LEFT,
	EDIR_NOCHANGE,
	EDIR_RIGHT,
};
enum ECollisionType
{
	ECT_NONE,
	ECT_WALL,
	ECT_BRICK
};

const unsigned char playboardTilesWidth = 10;
const unsigned char playboardTilesHeight = 10;
const unsigned char tileSize=16;
const unsigned short PlayboardPixelsWidth = playboardTilesWidth*tileSize;
const unsigned short PlayboardPixelsHeight = playboardTilesHeight*tileSize;
const unsigned short ScoreBoardWidth=300;
const unsigned short ScoreBoardHeight=PlayboardPixelsHeight;

#endif // !NITHRISCONSTANTS_H
