//PG4400 - INNLEVERING 1 - TRYM NILSEN
#include "Render.h"


Render::~Render()
{
	{
	SDL_DestroyRenderer(windowRenderPointer);
	SDL_DestroyWindow(gameWindowPointer);


	}
	SDL_Quit();

}
void Render::renderInit()
{
	//checks for render errors if so throw an exception
	if(!SDL_WasInit(SDL_INIT_VIDEO))
	{
		if(0>SDL_Init(SDL_INIT_VIDEO))
		{
			throw GraphicsInitEx("Could not initialize SDL");
		}
	}
	//create the window
	gameWindowPointer=SDL_CreateWindow("Nithris",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,PlayboardPixelsWidth+ScoreBoardWidth,PlayboardPixelsHeight,SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	if(gameWindowPointer==NULL)
		throw GraphicsInitEx("Failed creating window");
	windowRenderPointer=SDL_CreateRenderer(gameWindowPointer,-1,SDL_RENDERER_ACCELERATED);
	if(windowRenderPointer==NULL)
		throw GraphicsInitEx("Failed creating renderer for window");
	//Set render color
	SDL_SetRenderDrawColor(windowRenderPointer,0,0,255,255);
	//loading our textures
	brickTexture=LoadBmpFile("Assets/tiles_32x32.bmp");
	scoreBoardTexture=LoadBmpFile("Assets/scoreboard_back.bmp");
	numbersTexture=LoadBmpFile("Assets/numbers_32x32.bmp");
	welcomeTexture=LoadBmpFile("Assets/startup.bmp");
	pauseTexture=LoadBmpFile("Assets/pause.bmp");
	gameOverTexture=LoadBmpFile("Assets/gameover.bmp");


}
//Renders the playboard
void Render::renderPlayBoard(std::shared_ptr<Playboard> boardToBeRendered)
{
	//Loop through it and draw the appropriate color
	for(int y=0; y<playboardTilesHeight; y++)
	{
		for(int x=0; x<playboardTilesWidth; x++)
		{
			SDL_Rect tileSourceRect;
			SDL_Rect tileDestinationRect;
			ETileColor tileColor = boardToBeRendered->colorOfTileAt(x,y);
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
	nextPiecePos.X=11;
	nextPiecePos.Y=4;
	Position scorePos;
	scorePos.X=PlayboardPixelsWidth+40;
	scorePos.Y=340;
	Position highscorePos;
	highscorePos.X=PlayboardPixelsWidth+40;
	highscorePos.Y=430;
	DrawScoreboardBG();
	DrawPiece(nextPiece,&nextPiecePos);
	DrawNumber(currentScore,&scorePos);
	DrawNumber(highScore,&highscorePos);
}
void Render::promtUser(EPromtType& type)
{
	switch (type)
	{
	case PROMT_NEWGAME:
		DrawWelcomeMessage();
		break;
	case PROMT_GAMEOVER:
		DrawGameOverMessage();
		break;
	case PROMT_PAUSE:
		DrawPauseMessage();
		break;
	default:
		break;
	}
}
void Render::flipBuffers()
{
	SDL_RenderPresent(windowRenderPointer);
}

void Render::DrawWelcomeMessage()
{
	SDL_Rect tileDestinationRect;

	tileDestinationRect.x=120;
	tileDestinationRect.y=220;
	tileDestinationRect.w=260;
	tileDestinationRect.h=150;

	SDL_RenderCopy(windowRenderPointer,welcomeTexture.get(),NULL,&tileDestinationRect);
}

void Render::DrawPauseMessage()
{
	SDL_Rect tileDestinationRect;

	tileDestinationRect.x=120;
	tileDestinationRect.y=220;
	tileDestinationRect.w=260;
	tileDestinationRect.h=150;

	SDL_RenderCopy(windowRenderPointer,pauseTexture.get(),NULL,&tileDestinationRect);
}

void Render::DrawGameOverMessage()
{
	SDL_Rect tileDestinationRect;

	tileDestinationRect.x=120;
	tileDestinationRect.y=220;
	tileDestinationRect.w=260;
	tileDestinationRect.h=150;

	SDL_RenderCopy(windowRenderPointer,gameOverTexture.get(),NULL,&tileDestinationRect);
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
		DrawScoreDigit(position->X + (3 - usDigitSpot)*tileSize, position->Y, finalDigit);
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

	// When positions are set, the wanted tile to the screen.
	SDL_RenderCopy(windowRenderPointer, numbersTexture.get(), &oNumberRect, &oScreenRect);

}  // END _DrawScoreDigit


