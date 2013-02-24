//PG4400 - INNLEVERING 1 - TRYM NILSEN
#ifndef NITHRISCONSTANTS_H
#define NITHRISCONSTANTS_H
//Enum defining the color a tile can have
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
//enum defining our menu promt types
enum EPromtType
{
	PROMT_NEWGAME,
	PROMT_PAUSE,
	PROMT_GAMEOVER
};
//Enum defining the different movements or piece operations
enum EMovement
{
	EDIR_LEFT,
	EDIR_NOCHANGE,
	EDIR_RIGHT,
	EDIR_DROP,
	EDIR_ROTATE
};
//Enum define diffent collision types
enum ECollisionType
{
	ECT_NONE,
	ECT_WALL,
	ECT_BRICK
};
/*
    , |\/| ,
   /| (..) |\
  /  \(oo)/  \
 /    /''\    \
/    /\  /\    \
\/\/`\ \/ /`\/\/
^^-^^^^-^^^^^-^^^^ 
Here be dragons,
dont change this stuff as wrong values WILL make the program crash

*/
const int playboardTilesWidth = 10;
const int playboardTilesHeight = 20;
const int tileSize=32;
const short PlayboardPixelsWidth = playboardTilesWidth*tileSize;
const short PlayboardPixelsHeight = playboardTilesHeight*tileSize;
const short ScoreBoardWidth=256;
const short ScoreBoardHeight=PlayboardPixelsHeight;
const short StartDropSpeed=3;
const short dropSpeedUp=15;

#endif // !NITHRISCONSTANTS_H
