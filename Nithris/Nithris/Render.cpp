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
	brickTexture=loadBmpFile("Assets/tiles_32x32.bmp");
	scoreBoardTexture=loadBmpFile("Assets/scoreboard_back.bmp");
	numbersTexture=loadBmpFile("Assets/numbers_32x32.bmp");
	welcomeTexture=loadBmpFile("Assets/startup.bmp");
	pauseTexture=loadBmpFile("Assets/pause.bmp");
	gameOverTexture=loadBmpFile("Assets/gameover.bmp");


}
//Renders the playboard
void Render::renderPlayBoard(std::shared_ptr<Playboard> boardToBeRendered)
{
	//Loop through it and draw the appropriate color
	for(int y=0; y<PlayboardTilesHeight; y++)
	{
		for(int x=0; x<PlayboardTilesWidth; x++)
		{
			//find the color and draw it
			ETileColor tileColor = boardToBeRendered->colorOfTileAt(x,y);
			Position TilePos;
			TilePos.X=x;
			TilePos.Y=y;
			drawTile(tileColor,&TilePos);
		}
	}
}
//draw the scoreboard
void Render::renderScoreBoard(Piece& nextPiece, int currentScore, int highScore )
{
	//find positions
	Position nextPiecePos;
	nextPiecePos.X=11;
	nextPiecePos.Y=4;
	Position scorePos;
	scorePos.X=PlayboardPixelsWidth+40;
	scorePos.Y=340;
	Position highscorePos;
	highscorePos.X=PlayboardPixelsWidth+40;
	highscorePos.Y=430;
	drawScoreboardBG();
	drawPiece(nextPiece,&nextPiecePos);
	drawNumber(currentScore,&scorePos);
	drawNumber(highScore,&highscorePos);
}
void Render::promtUser(EPromtType& type)
{
	//Switch to the correct promt based on parameter
	switch (type)
	{
	case PROMT_NEWGAME:
		drawWelcomeMessage();
		break;
	case PROMT_GAMEOVER:
		drawGameOverMessage();
		break;
	case PROMT_PAUSE:
		drawPauseMessage();
		break;
	default:
		break;
	}
}
//presents the render
void Render::flipBuffers()
{
	SDL_RenderPresent(windowRenderPointer);
}

///PROMT MESSAGES
void Render::drawWelcomeMessage()
{
	//gets the desination and draw the texture
	SDL_Rect tileDestinationRect;

	tileDestinationRect.x=120;
	tileDestinationRect.y=220;
	tileDestinationRect.w=260;
	tileDestinationRect.h=150;

	SDL_RenderCopy(windowRenderPointer,welcomeTexture.get(),NULL,&tileDestinationRect);
}

void Render::drawPauseMessage()
{
	//gets the desination and draw the texture
	SDL_Rect tileDestinationRect;

	tileDestinationRect.x=120;
	tileDestinationRect.y=220;
	tileDestinationRect.w=260;
	tileDestinationRect.h=150;

	SDL_RenderCopy(windowRenderPointer,pauseTexture.get(),NULL,&tileDestinationRect);
}

void Render::drawGameOverMessage()
{
	//gets the desination and draw the texture
	SDL_Rect tileDestinationRect;

	tileDestinationRect.x=120;
	tileDestinationRect.y=220;
	tileDestinationRect.w=260;
	tileDestinationRect.h=150;

	SDL_RenderCopy(windowRenderPointer,gameOverTexture.get(),NULL,&tileDestinationRect);
}

void Render::drawPiece(Piece& pieceToDraw, Position *position)
{
	//draws a piece by itterating through its array and if the tile is marked it is drawn
	for(int y=0; y<4; y++)
	{
		for(int x=0; x<4; x++)
		{
			if(pieceToDraw.tileAt(x,y))
			{
				Position tilePosition;
				tilePosition.X=position->X+x;
				tilePosition.Y=position->Y+y;
				drawTile(pieceToDraw.PieceColor,&tilePosition);
			}
		}
	}
}

void Render::drawNumber(unsigned short number, Position *position )
{
	//Taken from assignment example
	// Render the scoretext output.
	unsigned short tempScore = number;
	unsigned short finalDigit = 0;
	for (unsigned short usDigitSpot = 0; usDigitSpot < 4; ++usDigitSpot)
	{
		finalDigit = tempScore % 10;
		tempScore /= 10;
		drawScoreDigit(position->X + (3 - usDigitSpot)*TileSize, position->Y, finalDigit);
	}
}

void Render::drawTile(ETileColor& color,Position *position)
{
	///Draws the tile at the specified position with the specified color
	SDL_Rect tileSourceRect;
	SDL_Rect tileDestinationRect;
	tileSourceRect.x=color*TileSize;
	tileSourceRect.y=0;
	tileSourceRect.w=TileSize;
	tileSourceRect.h=TileSize;

	tileDestinationRect.x=position->X*TileSize;
	tileDestinationRect.y=position->Y*TileSize;
	tileDestinationRect.w=TileSize;
	tileDestinationRect.h=TileSize;

	SDL_RenderCopy(windowRenderPointer,brickTexture.get(),&tileSourceRect,&tileDestinationRect);
}

//Loads a bmp file
std::shared_ptr<SDL_Texture>  Render::loadBmpFile( const char* filename )
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

void Render::drawScoreboardBG()
{
	//gets the position to draw the scoreboard background
	SDL_Rect destinationRect;
	destinationRect.x=PlayboardPixelsWidth;
	destinationRect.y=0;
	destinationRect.w=ScoreBoardWidth;
	destinationRect.h=ScoreBoardHeight;
	SDL_RenderCopy(windowRenderPointer,scoreBoardTexture.get(),NULL,&destinationRect);
}
void Render::drawScoreDigit(short sPosX, short sPosY, unsigned short usDigit) 
{
	//take from assignment example
	SDL_Rect oScreenRect;  // Part of screen we want to draw to.
	SDL_Rect oNumberRect;  // Part of the number-bmp-file (all numbers are stored in a single bmp, and we use a small part of it) we want to draw from.

	oScreenRect.x = sPosX; 
	oScreenRect.y = sPosY;
	oScreenRect.w = TileSize;
	oScreenRect.h = TileSize;

	oNumberRect.x = usDigit * TileSize;   
	oNumberRect.y = 0;
	oNumberRect.w = TileSize;   
	oNumberRect.h = TileSize;

	// When positions are set, the wanted tile to the screen.
	SDL_RenderCopy(windowRenderPointer, numbersTexture.get(), &oNumberRect, &oScreenRect);

}  // END _DrawScoreDigit


