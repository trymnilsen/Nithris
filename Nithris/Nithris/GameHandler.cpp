#include "GameHandler.h"

void GameHandler::initGame()
{
	gameRender.swap(std::unique_ptr<Render>(new Render()));
	gameRender->renderInit();
	gameOver=false;
	CurrentRound = std::unique_ptr<Round>(new Round());
	RequestedDirection=EDIR_NOCHANGE;
}

void GameHandler::runGame()
{
	//Timer for Checking for input
	LoopTimer inputTimer(1000);
	//Timer for rendering, no need for more than 60fps
	LoopTimer renderTimer(60);
	//Timer for moving the block down a notch
	LoopTimer MovementTickTimer(3);
	//Timer for modifing the brick, move it left/right or rotate it. (we save the requested action in each input update but only process it here.. did this to give the game a more old feel with a little fake lag)
	LoopTimer BrickOperations(10);

	inputTimer.Start();
	renderTimer.Start();
	MovementTickTimer.Start();

	while(!gameOver)
	{
		if(MovementTickTimer.IsTimeForUpdate())
		{
			movePiece(EDIR_DROP);
			RequestedDirection=EDIR_NOCHANGE;
			processPlayboard();
		}
		if(renderTimer.IsTimeForUpdate())
		{
			renderPlayboard();
			renderScoreBoard();
			gameRender->DrawPiece(*CurrentRound->getCurrentPiece().get(),&CurrentRound->getCurrentPiece()->piecePosition);
			gameRender->flipBuffers();
		}
		if(BrickOperations.IsTimeForUpdate())
		{
			movePiece(RequestedDirection);
			RequestedDirection=EDIR_NOCHANGE;
		}
		InputManagerSDL::Instance().Update();
		//Input
		if (InputManagerSDL::Instance().KeyDown(SDL_SCANCODE_LEFT))
		{
			RequestedDirection=EDIR_LEFT;
		}

		if (InputManagerSDL::Instance().KeyDown(SDL_SCANCODE_RIGHT))
		{
			RequestedDirection=EDIR_RIGHT;
		}
		if(InputManagerSDL::Instance().KeyDown(SDL_SCANCODE_SPACE))
		{
			RequestedDirection=EDIR_ROTATE;		
		}

		//
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

void GameHandler::movePiece(EMovement wantedMove)
{
	if(wantedMove!=EDIR_NOCHANGE)
	{
		std::shared_ptr<Piece> ghost = CurrentRound->getCurrentPiece()->CreateGhost(wantedMove);
		ECollisionType collisionType = checkCollision(ghost);
		if(!collisionType)
		{
				std::cout<<"moving orignal piece:"<<CurrentRound->getCurrentPiece()->piecePosition.Y<<std::endl<<"ghost"<<ghost->piecePosition.Y<<::std::endl;
				CurrentRound->setCurrentPiece(ghost);
				std::cout<<"new current"<<CurrentRound->getCurrentPiece()->piecePosition.Y<<std::endl;
				
		} 
		else if(collisionType==ECT_BRICK)
		{
			CurrentRound->getPlayboard()->setPieceAt(CurrentRound->getCurrentPiece()->piecePosition.X,CurrentRound->getCurrentPiece()->piecePosition.Y,*CurrentRound->getCurrentPiece().get());
			CurrentRound->getCurrentPiece()->piecePosition.Y=1;
			CurrentRound->getCurrentPiece()->piecePosition.X=4;
		}


	}
}


ECollisionType GameHandler::checkCollision(std::shared_ptr<Piece> piece)
{
	for (int y=0; y<4; y++)
	{
		for(int x=0; x<4; x++)
		{
			if(piece->tileAt(x,y))
			{

				if(piece->piecePosition.X+x<0 || piece->piecePosition.X+x>playboardTilesWidth-1)
				{
					return ECT_WALL;
				}
				else if(piece->piecePosition.Y+y>playboardTilesHeight-1 || CurrentRound->getPlayboard()->colorOfTileAt(piece->piecePosition.X+x,piece->piecePosition.Y+y)>0)
				{
					return ECT_BRICK;
				}

				
			}
			
		}
	}
	return ECT_NONE;
}



