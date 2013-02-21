#include "Render.h"

Render::Render()
{

}

Render::~Render()
{
	SDL_DestroyRenderer(windowRenderPointer);
	SDL_DestroyWindow(gameWindowPointer);
	SDL_Quit();
}
void Render::renderInit()
{
	if(!SDL_WasInit(SDL_INIT_VIDEO))
	{
		if(0>SDL_Init(SDL_INIT_VIDEO))
		{
			throw GraphicsInitEx("Test");
		}
	}

	gameWindowPointer=SDL_CreateWindow("Nithris changethis",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,PlayboardPixelsWidth+ScoreBoardWidth,PlayboardPixelsHeight,SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	if(gameWindowPointer==NULL)
		throw GraphicsInitEx("Failed creating window");
	windowRenderPointer=SDL_CreateRenderer(gameWindowPointer,-1,SDL_RENDERER_ACCELERATED);
	if(windowRenderPointer==NULL)
		throw GraphicsInitEx("Failed creating renderer for window");
	//Set render color
	SDL_SetRenderDrawColor(windowRenderPointer,0,0,255,255);
	brickTexture=LoadBmpFile("Assets/tiles_32x32.bmp");
	scoreBoardTexture=LoadBmpFile("Assets/scoreboard_back.bmp");

}

void Render::renderPlayBoard(std::shared_ptr<Playboard> boardToBeRendered)
{

	for(int y=0; y<playboardTilesHeight; y++)
	{
		for(int x=0; x<playboardTilesWidth; x++)
		{
			SDL_Rect tileSourceRect;
			SDL_Rect tileDestinationRect;
			const ETileColor tileColor = boardToBeRendered->colorOfTileAt(x,y);
			tileSourceRect.x=tileColor*tileSize;
			tileSourceRect.y=0;
			tileSourceRect.w=tileSize;
			tileSourceRect.h=tileSize;

			tileDestinationRect.x=x*tileSize;
			tileDestinationRect.y=y*tileSize;
			tileDestinationRect.w=tileSize;
			tileDestinationRect.h=tileSize;
			SDL_RenderCopy(windowRenderPointer,brickTexture.get(),&tileSourceRect,&tileDestinationRect);
		}

	}
	
}

void Render::renderScoreBoard(Piece& nextPiece, int currentScore, int highScore )
{
	SDL_Rect piecePos;
	piecePos.x=PlayboardPixelsWidth+50;
	piecePos.y=50;
	piecePos.w=4*tileSize;
	piecePos.h=4*tileSize;
	DrawScoreboardBG();
	DrawPiece(nextPiece,&piecePos);
	DrawNumber(currentScore,&piecePos);
	DrawNumber(highScore,&piecePos);
}
void Render::promtUser(EPromtType& type)
{

}
void Render::flipBuffers()
{
	SDL_RenderPresent(windowRenderPointer);
}
SDL_Renderer* Render::getRenderer()
{
	return windowRenderPointer;
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

void Render::DrawPiece(Piece& pieceToDraw, SDL_Rect *position )
{
	for(int y=0; y<4; y++)
	{
		for(int x=0; x<4; x++)
		{
			if(pieceToDraw.tileAt(x,y))
			{
				Position tilePosition;
				tilePosition.X=position->x+x*tileSize;
				tilePosition.Y=position->y+y*tileSize;
				DrawTile(pieceToDraw.PieceColor,&tilePosition);
			}
		}
	}
}

void Render::DrawNumber(int number, SDL_Rect *position )
{

}

void Render::DrawTile(ETileColor& color,Position *position)
{
	SDL_Rect tileSourceRect;
	SDL_Rect tileDestinationRect;
	tileSourceRect.x=color*tileSize;
	tileSourceRect.y=0;
	tileSourceRect.w=tileSize;
	tileSourceRect.h=tileSize;

	tileDestinationRect.x=position->X;
	tileDestinationRect.y=position->Y;
	tileDestinationRect.w=tileSize;
	tileDestinationRect.h=tileSize;

	SDL_RenderCopy(windowRenderPointer,brickTexture.get(),&tileSourceRect,&tileDestinationRect);
}

std::shared_ptr<SDL_Texture>  Render::LoadBmpFile( const char* filename )
{
	try{
	SDL_Surface *loadedFile=SDL_LoadBMP(filename);
	if(!loadedFile)
		throw GraphicsInitEx("Failed loading file");

	std::shared_ptr<SDL_Texture> returnTexture(SDL_CreateTextureFromSurface(windowRenderPointer,loadedFile));
	SDL_FreeSurface(loadedFile);
	return returnTexture;
	}
	catch(GraphicsInitEx ge)
	{
		std::cout<<ge.what()<<std::endl;
	}
	
	return NULL;
}

void Render::DrawScoreboardBG()
{
	SDL_Rect destinationRect;
	destinationRect.x=PlayboardPixelsWidth;
	destinationRect.y=0;
	destinationRect.w=ScoreBoardWidth;
	destinationRect.h=ScoreBoardHeight;
	SDL_RenderCopy(windowRenderPointer,scoreBoardTexture.get(),NULL,&destinationRect);
}


