#include "GameHandler.h"

GameHandler::GameHandler()
{

}

GameHandler::GameHandler( const GameHandler& )
{

}

GameHandler& GameHandler::operator=( const GameHandler& )
{

}

void GameHandler::initGame()
{
	Render gameRender;
	gameRender.renderInit();

}

void GameHandler::runGame()
{

}

void GameHandler::cleanUpGame()
{

}

void GameHandler::prompUser()
{

}

void GameHandler::renderPlayboard()
{

}

void GameHandler::renderScoreBoard()
{

}

void GameHandler::processPlayboard()
{

}

void GameHandler::startNewGame()
{

}

void GameHandler::getNewPiece()
{

}

void GameHandler::moveCurrentPiece()
{

}

std::shared_ptr<SDL_Texture> GameHandler::LoadAsset(const char* filename )
{
	SDL_Surface *loadedFile=SDL_LoadBMP(filename);
	if(!loadedFile)
		throw GraphicsInitEx("Failed loading file");
	
	std::shared_ptr<SDL_Texture> returnTexture;
	returnTexture=SDL_CreateTextureFromSurface(gameRender.get()->getRenderer(),loadedFile);
	return returnTexture;
}

std::shared_ptr<SDL_Texture> GameHandler::getAsset( ETexture requestedAsset )
{
	return Content[requestedAsset];
}


