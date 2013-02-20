#ifndef NITHRISCONSTANTS_H
#define NITHRISCONSTANTS_H
enum ETexture{
	BRICKS,
	SCOREBOARD,
	PAUSESCREEN,
	WELCOMESCREEN,
	ENDSCREEN
};

const unsigned char playboardTilesWidth = 10;
const unsigned char playboardTilesHeight = 10;
const unsigned char tileSize=16;
const unsigned short PlayboardPixelsWidth = playboardTilesWidth*tileSize;
const unsigned short PlayboardPixelsHeight = playboardTilesHeight*tileSize;
const unsigned short ScoreBoardWidth=300;
const unsigned short ScoreBoardHeight=PlayboardPixelsHeight;

#endif // !NITHRISCONSTANTS_H
