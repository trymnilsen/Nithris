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
			throw GraphicsInitEx("Could not initialize SDL");
		}
	}

	gameWindowPointer=SDL_CreateWindow("Nithris",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,PlayboardPixelsWidth+ScoreBoardWidth,PlayboardPixelsHeight,SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	if(gameWindowPointer==NULL)
		throw GraphicsInitEx("Failed creating window");
	windowRenderPointer=SDL_CreateRenderer(gameWindowPointer,-1,SDL_RENDERER_ACCELERATED);
	if(windowRenderPointer==NULL)
		throw GraphicsInitEx("Failed creating renderer for window");
	//Set render color
	SDL_SetRenderDrawColor(windowRenderPointer,0,0,255,255);
	brickTexture=LoadBmpFile("Assets/tiles_32x32.bmp");
	scoreBoardTexture=LoadBmpFile("Assets/scoreboard_back.bmp");
	numbersTexture=LoadBmpFile("Assets/numbers_32x32.bmp");


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
	Position nextPiecePos;
	nextPiecePos.X=400;
	nextPiecePos.Y=50;
	DrawScoreboardBG();
	DrawPiece(nextPiece,&nextPiecePos);
	//DrawNumber(currentScore,&nextPiecePos);
	//DrawNumber(highScore,&nextPiecePos);
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

void Render::DrawPiece(Piece& pieceToDraw, Position *position)
{
	for(int y=0; y<4; y++)
	{
		for(int x=0; x<4; x++)
		{
			if(pieceToDraw.tileAt(x,y))
			{
				Position tilePosition;
				tilePosition.X=position->X+x;
				tilePosition.Y=position->Y+y;
				DrawTile(pieceToDraw.PieceColor,&tilePosition);
			}
		}
	}
}

void Render::DrawNumber(unsigned short number, Position *position )
{
	// Render the scoretext output.
	unsigned short tempScore = number;
	unsigned short finalDigit = 0;
	for (unsigned short usDigitSpot = 0; usDigitSpot < 4; ++usDigitSpot)
	{
		finalDigit = tempScore % 10;
		tempScore /= 10;
		DrawScoreDigit(position->X + (3 - usDigitSpot), position->Y, finalDigit);
	}
}

void Render::DrawTile(ETileColor& color,Position *position)
{
	SDL_Rect tileSourceRect;
	SDL_Rect tileDestinationRect;
	tileSourceRect.x=color*tileSize;
	tileSourceRect.y=0;
	tileSourceRect.w=tileSize;
	tileSourceRect.h=tileSize;

	tileDestinationRect.x=position->X*tileSize;
	tileDestinationRect.y=position->Y*tileSize;
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
void Render::DrawScoreDigit(short sPosX, short sPosY, unsigned short usDigit) 
{
	SDL_Rect oScreenRect;  // Part of screen we want to draw to.
	SDL_Rect oNumberRect;  // Part of the number-bmp-file (all numbers are stored in a single bmp, and we use a small part of it) we want to draw from.

	oScreenRect.x = sPosX; 
	oScreenRect.y = sPosY;
	oScreenRect.w = tileSize;
	oScreenRect.h = tileSize;

	oNumberRect.x = usDigit * tileSize;   
	oNumberRect.y = 0;
	oNumberRect.w = tileSize;   
	oNumberRect.h = tileSize;

	// When positions are set, blit the wanted tile to the screen.
	SDL_RenderCopy(windowRenderPointer, numbersTexture.get(), &oNumberRect, &oScreenRect);

}  // END _DrawScoreDigit


