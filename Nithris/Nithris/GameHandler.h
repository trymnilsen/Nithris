#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H

#include <SDL.h>

class GameHandler
{
public:
	static GameHandler& instance()
	{
		static GameHandler gh;
		return gh;
	}
	void initGame();
	void runGame();
	void cleanUpGame();

private:
	GameHandler();
	GameHandler(const GameHandler&);
	GameHandler& operator=(const GameHandler&);
	
	void prompUser();
	void renderPlayboard();
	void renderScoreBoard();
	void processPlayboard();
	void startNewGame();
	void getNewPiece();
	void moveCurrentPiece();
	SDL_Texture *LoadAsset(const char* filename);
	
};

#endif

