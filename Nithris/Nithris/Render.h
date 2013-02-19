#ifndef RENDER_H
#define RENDER_H

#include"Playboard.h"
#include"Piece.h"
#include"SDL.h"
#include"PromptType.h"
#include"NithrisConstants.h"
#include"TileColor.h"

class Render
{
public:
	Render();
	~Render();
	void renderPlayBoard(const Playboard& boardToBeRendered);
	void renderScoreBoard(Piece& nextPiece, int currentScore, int highScore);
	void promtUser(EPromtType& type);
	void flipBuffers();
private:
	void DrawWelcomeMessage();
	void DrawPauseMessage();
	void DrawGameOverMessage();

	SDL_Window *gameWindowPointer;
	SDL_Renderer *windowRenderPointer;
	SDL_Surface *backBuffer;
	
};
#endif