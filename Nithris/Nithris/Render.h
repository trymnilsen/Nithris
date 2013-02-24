//PG4400 - INNLEVERING 1 - TRYM NILSEN
//Renderering class written because of curriosity
#ifndef RENDER_H
#define RENDER_H

#include <memory>
#include <iostream>

#include "Playboard.h"
#include "Piece.h"
#include "SDL.h"
#include "NithrisConstants.h"
#include "GraphicsInitEx.h"
#include "Playboard.h"
#include "Position.h"


class Render
{
public:
	Render(){};
	~Render();
	//initializes the renderer, 
	void renderInit();
	//Render the playboard
	void renderPlayBoard(std::shared_ptr<Playboard> boardToBeRendered);
	//render the scoreBoard
	void renderScoreBoard(Piece& nextPiece, int currentScore, int highScore);
	//draw a piece at the position !NOTE:! position is in a 32x32 grid not pixels
	void DrawPiece(Piece& pieceToDraw, Position *position);
	//draw the promt menus
	void promtUser(EPromtType& type);
	//Realize this might not be the perfect name, but presents the render buffer 
	void flipBuffers();

private:
	//Draws a tile
	void DrawTile(ETileColor& color,Position *position);
	//Draws a number taken from example wrapper class
	void DrawNumber(unsigned short number,Position *position);
	//Draws the promt menues
	void DrawWelcomeMessage();
	void DrawPauseMessage();
	void DrawGameOverMessage();
	//Draws the scoreboardBackground
	void DrawScoreboardBG();
	//draws a single digit
	void DrawScoreDigit(short sPosX, short sPosY, unsigned short usDigit);

	//Method for loading a BMP file and retunrns a shared pointer to it
	std::shared_ptr<SDL_Texture> LoadBmpFile(const char* filename);
	//Points to out windows and renderers
	SDL_Window *gameWindowPointer;
	SDL_Renderer *windowRenderPointer;

	//Shared pointers to our graphics
	std::shared_ptr<SDL_Texture> brickTexture;
	std::shared_ptr<SDL_Texture> numbersTexture;
	std::shared_ptr<SDL_Texture> scoreBoardTexture;
	std::shared_ptr<SDL_Texture> welcomeTexture;
	std::shared_ptr<SDL_Texture> pauseTexture;
	std::shared_ptr<SDL_Texture> gameOverTexture;

	
};
#endif