#include "Render.h"
#include "GraphicsInitEx.h"
#include "TileColor.h"
#include "Playboard.h"

Render::Render()
{
	if(!SDL_WasInit(SDL_INIT_VIDEO))
	{
		if(0>SDL_Init(SDL_INIT_VIDEO))
		{
			throw GraphicsInitEx("Test");
		}
	}

	gameWindowPointer=SDL_CreateWindow("Nithris changethis",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,300,550,SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	if(gameWindowPointer==NULL)
		throw GraphicsInitEx("Failed creating window");
	windowRenderPointer=SDL_CreateRenderer(gameWindowPointer,-1,SDL_RENDERER_ACCELERATED);
	if(windowRenderPointer==NULL)
		throw GraphicsInitEx("Failed creating renderer for window");
	//Set render color
	SDL_SetRenderDrawColor(windowRenderPointer,0,0,0,255);
}

Render::~Render()
{

}

void Render::renderPlayBoard(Playboard& boardToBeRendered)
{
	for(char y=0; y<playboardTilesHeight; y++)
	{
		for(char x=0; x<playboardTilesWidth; x++)
		{
			SDL_Rect tileSourceRect;
			SDL_Rect tileDestinationRect;
			const ETileColor tileColor = boardToBeRendered.colorOfTileAt(x,y);
			tileSourceRect.x=tileColor*tileSize;
			tileSourceRect.y=0;
			tileSourceRect.w=tileSize;
			tileSourceRect.h=tileSize;

			SDL_RenderCopy(windowRenderPointer,NULL,&tileSourceRect,&tileDestinationRect);
		}
	}
	
}

void Render::renderScoreBoard(Piece& nextPiece, int currentScore, int highScore )
{

}

void Render::promtUser(EPromtType& type)
{

}

void Render::flipBuffers()
{

}

void Render::DrawWelcomeMessage()
{

}

void Render::DrawPauseMessage()
{

}

void Render::DrawGameOverMessage()
{

}

