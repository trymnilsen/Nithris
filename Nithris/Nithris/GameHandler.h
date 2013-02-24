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
#include "InputManagerSDL.h"

class GameHandler
{
public:
	//standard meyers singleton pattern
	static GameHandler& instance()
	{
		static GameHandler gh;
		return gh;
	}
	//Initialize the game and core valeus
	void initGame();
	//start the gameloop, running all our logic
	void runGame();
	//clean up 
	void cleanUpGame();
private:
	//private construction enabling us to only call it from within itself
	GameHandler(){};
	GameHandler(const GameHandler&);
	GameHandler& operator=(const GameHandler&);
	
	//Vial gameplay methods
	void gamePlayInput();
	void menuInput();
	void renderPlayboard();
	void renderScoreBoard();
	void processPlayboard();
	void movePiece(EMovement wantedMove);
	ECollisionType checkCollision(std::shared_ptr<Piece> piece, EMovement wantedMove);

	//smartpoints for core gameplay objects
	std::unique_ptr<Render> gameRender;
	std::unique_ptr<Piece> CurrentPiece;
	std::unique_ptr<Round> CurrentRound;
	//is the game over, or should we prompt the user?
	bool gameOver;
	bool MenuActive;
	int highScore;
	EPromtType activeMenu;
	//what does the user want to do?
	EMovement requestedDirection;
	//Timers, enabling us to both put the program to sleep decreasing cpu usage and get accurate timing for gameplay elements
	LoopTimer inputTimer;
	LoopTimer updateTimer;
	LoopTimer MovementTickTimer;


};

#endif

