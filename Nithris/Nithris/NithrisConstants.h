#ifndef NITHRISCONSTANTS_H
#define NITHRISCONSTANTS_H

enum ETileColor
{
	TC_NO_DRAW = -1,
	TC_BACKGROUND,
	TC_ORANGE ,
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
enum EMovement
{
	EDIR_LEFT,
	EDIR_NOCHANGE,
	EDIR_RIGHT,
	EDIR_DROP,
	EDIR_ROTATE
};
enum ECollisionType
{
	ECT_NONE,
	ECT_WALL,
	ECT_BRICK
};

const int playboardTilesWidth = 10;
const int playboardTilesHeight = 20;
const int tileSize=32;
const short PlayboardPixelsWidth = playboardTilesWidth*tileSize;
const short PlayboardPixelsHeight = playboardTilesHeight*tileSize;
const short ScoreBoardWidth=256;
const short ScoreBoardHeight=PlayboardPixelsHeight;

#endif // !NITHRISCONSTANTS_H
