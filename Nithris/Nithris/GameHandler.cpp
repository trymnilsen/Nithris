#include "GameHandler.h"

void GameHandler::initGame()
{
	gameRender.swap(std::unique_ptr<Render>(new Render()));
	gameRender->renderInit();
	gameOver=false;
	CurrentRound = std::unique_ptr<Round>(new Round());
}

void GameHandler::runGame()
{
	LoopTimer inputTimer(1000);
	LoopTimer renderTimer(60);
	LoopTimer movementTimer(1);

	inputTimer.Start();
	renderTimer.Start();
	movementTimer.Start();

	while(!gameOver)
	{
		if(movementTimer.IsTimeForUpdate())
		{
			moveCurrentPiece();
			processPlayboard();
		}
		if(renderTimer.IsTimeForUpdate())
		{
			renderPlayboard();
			renderScoreBoard();
			gameRender->flipBuffers();
		}
		inputTimer.SleepUntilUpdate();
	}

}

void GameHandler::cleanUpGame()
{

}

void GameHandler::prompUser()
{

}

void GameHandler::renderPlayboard()
{
	gameRender->renderPlayBoard(CurrentRound->getPlayboard());
}

void GameHandler::renderScoreBoard()
{
	gameRender->renderScoreBoard(CurrentRound->getNextPiece(),1000,50);
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


