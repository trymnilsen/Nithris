#ifndef RENDER_H
#define RENDER_H

#include"Playboard.h"
#include"Piece.h"
#include"SDL.h"
#include"PromptType.h"

class Render
{
public:
	Render();
	~Render();
	void renderPlayBoard(Playboard& boardToBeRendered);
	void renderScoreBoard(Piece& nextPiece, int currentScore, int highScore);
	void promtUser(EPromtType& type);
	void flipBuffers();
private:
	void DrawWelcomeMessage();
	void DrawPauseMessage();
	void DrawGameOverMessage();
	
};
#endif