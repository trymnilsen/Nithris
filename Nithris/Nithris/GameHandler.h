#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H

#include <SDL.h>
#include <memory>
#include <vector>

#include "Render.h"
#include "GraphicsInitEx.h"
#include "NithrisConstants.h"
#include "LoopTimer.h"
#include "Round.h"

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
	GameHandler(){};
	GameHandler(const GameHandler&);
	GameHandler& operator=(const GameHandler&);
	
	void prompUser();
	void renderPlayboard();
	void renderScoreBoard();
	void processPlayboard();
	void startNewGame();
	void getNewPiece();
	void moveCurrentPiece();

	std::unique_ptr<Render> gameRender;
	std::unique_ptr<Piece> CurrentPiece;
	std::unique_ptr<Round> CurrentRound;
	bool gameOver;
	bool finishedPlaying;
};

#endif

