#ifndef RENDER_H
#define RENDER_H

#include <memory>
#include <iostream>

#include "Playboard.h"
#include "Piece.h"
#include "SDL.h"
#include "PromptType.h"
#include "NithrisConstants.h"
#include "GraphicsInitEx.h"
#include "Playboard.h"
#include "Position.h"


class Render
{
public:
	Render();
	~Render();
	void renderInit();
	void renderPlayBoard(std::shared_ptr<Playboard> boardToBeRendered);
	void renderScoreBoard(Piece& nextPiece, int currentScore, int highScore);
	void DrawPiece(Piece& pieceToDraw, Position *position);
	void promtUser(EPromtType& type);
	void flipBuffers();
	SDL_Renderer *getRenderer();
private:
	void DrawTile(ETileColor& color,Position *position);
	void DrawNumber(unsigned short number,Position *position);
	void DrawWelcomeMessage();
	void DrawPauseMessage();
	void DrawGameOverMessage();
	void DrawScoreboardBG();
	void DrawScoreDigit(short sPosX, short sPosY, unsigned short usDigit);

	std::shared_ptr<SDL_Texture> LoadBmpFile(const char* filename);
	SDL_Window *gameWindowPointer;
	SDL_Renderer *windowRenderPointer;

	std::shared_ptr<SDL_Texture> brickTexture;
	std::shared_ptr<SDL_Texture> numbersTexture;
	std::shared_ptr<SDL_Texture> scoreBoardTexture;

	
};
#endif