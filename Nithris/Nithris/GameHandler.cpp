#include "GameHandler.h"

void GameHandler::initGame()
{
	gameRender=std::unique_ptr<Render>(new Render());
	gameRender->renderInit();
	gameOver=false;
	CurrentRound = std::unique_ptr<Round>(new Round());
	RequestedDirection=EDIR_NOCHANGE;
	activeMenu=PROMT_NEWGAME;
	MenuActive=true;
	//Timers
	inputTimer.SetUpdatesPerInterval(1000);
	updateTimer.SetUpdatesPerInterval(100);
	MovementTickTimer.SetUpdatesPerInterval(StartDropSpeed);
	
}
void GameHandler::runGame()
{
	//Timer for Checking for input
	//Timer for modifing the brick, move it left/right or rotate it. (we save the requested action in each input update but only process it here.. did this to give the game a more old feel with a little fake lag)

	inputTimer.Start();
	updateTimer.Start();
	MovementTickTimer.Start();
	while(!gameOver)
	{
		if(MovementTickTimer.IsTimeForUpdate() && !MenuActive)
		{
			movePiece(EDIR_DROP);
			RequestedDirection=EDIR_NOCHANGE;
			processPlayboard();
		}
		if(updateTimer.IsTimeForUpdate())
		{
			
			if(!MenuActive)
			{
				movePiece(RequestedDirection);
				RequestedDirection=EDIR_NOCHANGE;
			}
			renderPlayboard();
			renderScoreBoard();
			gameRender->DrawPiece(*CurrentRound->getCurrentPiece().get(),&CurrentRound->getCurrentPiece()->piecePosition);
			if(MenuActive)
			{
				gameRender->promtUser(activeMenu);
			}
			gameRender->flipBuffers();
		}

		InputManagerSDL::Instance().Update();
		//Input
		if(!MenuActive)
		{
		//
			GamePlayInput();
			if(CurrentRound->getPlayboard()->checkGameOver())
			{
				activeMenu=PROMT_GAMEOVER;
				MenuActive=true;
			}
		}
		else
		{
			MenuInput();
		}
		if(InputManagerSDL::Instance().userExit())
		{
			gameOver=true;
		}

		//
		inputTimer.SleepUntilUpdate();
	}

}

void GameHandler::cleanUpGame()
{
	gameRender.release();
	CurrentPiece.release();
	CurrentRound.release();
}

void GameHandler::renderPlayboard()
{
	gameRender->renderPlayBoard(CurrentRound->getPlayboard());
}

void GameHandler::renderScoreBoard()
{
	gameRender->renderScoreBoard(*CurrentRound->getNextPiece().get(),CurrentRound->score,50);
}

void GameHandler::processPlayboard()
{
	bool hasRowsBeenRemoved=CurrentRound->getPlayboard()->checkBoard();
	if(hasRowsBeenRemoved)
	{
		CurrentRound->score+=10;
		CurrentRound->dropSpeed+=.3;
		MovementTickTimer.SetUpdatesPerInterval(CurrentRound->dropSpeed);
		MovementTickTimer.Start();
	}
}


void GameHandler::startNewGame()
{

}

void GameHandler::movePiece(EMovement wantedMove)
{
	if(wantedMove!=EDIR_NOCHANGE)
	{
		std::shared_ptr<Piece> ghost = CurrentRound->getCurrentPiece()->CreateGhost(wantedMove);
		ECollisionType collisionType = checkCollision(ghost,wantedMove);
		if(!collisionType)
		{
				std::cout<<"moving orignal piece:"<<CurrentRound->getCurrentPiece()->piecePosition.Y<<std::endl<<"ghost"<<ghost->piecePosition.Y<<::std::endl;
				CurrentRound->setCurrentPiece(ghost);
				std::cout<<"new current"<<CurrentRound->getCurrentPiece()->piecePosition.Y<<std::endl;
				
		} 
		else if(collisionType==ECT_BRICK)
		{
			CurrentRound->getPlayboard()->setPieceAt(CurrentRound->getCurrentPiece()->piecePosition.X,CurrentRound->getCurrentPiece()->piecePosition.Y,*CurrentRound->getCurrentPiece().get());
			CurrentRound->setCurrentPiece(CurrentRound->getNextPiece());
			CurrentRound->generateNextPiece();
			MovementTickTimer.SetUpdatesPerInterval(CurrentRound->dropSpeed);
			MovementTickTimer.Start();
		}


	}
}


ECollisionType GameHandler::checkCollision(std::shared_ptr<Piece> piece, EMovement wantedMove)
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
				//We split this into several ifs making it easier to read, eventough the return the same value
				else if(piece->piecePosition.Y+y>playboardTilesHeight-1)
				{
					return ECT_BRICK;
				}
				else if(CurrentRound->getPlayboard()->colorOfTileAt(piece->piecePosition.X+x,piece->piecePosition.Y+y)>0 && wantedMove==EDIR_DROP)
				{
					return ECT_BRICK;
				}
				else if(CurrentRound->getPlayboard()->colorOfTileAt(piece->piecePosition.X+x,piece->piecePosition.Y+y)>0 && (wantedMove==EDIR_LEFT || wantedMove==EDIR_RIGHT || wantedMove==EDIR_ROTATE))
				{
					return ECT_WALL;
				}
				
			}
			
		}
	}
	return ECT_NONE;
}

void GameHandler::GamePlayInput()
{
	if (InputManagerSDL::Instance().KeyDown(SDL_SCANCODE_LEFT))
	{
		RequestedDirection=EDIR_LEFT;
	}

	else if (InputManagerSDL::Instance().KeyDown(SDL_SCANCODE_RIGHT))
	{
		RequestedDirection=EDIR_RIGHT;
	}
	else if(InputManagerSDL::Instance().KeyDown(SDL_SCANCODE_SPACE))
	{
		RequestedDirection=EDIR_ROTATE;		
	}
	else if(InputManagerSDL::Instance().KeyDown(SDL_SCANCODE_DOWN))
	{
		MovementTickTimer.SetUpdatesPerInterval(CurrentRound->dropSpeed*dropSpeedUp);
		MovementTickTimer.Start();
	}
	else if(InputManagerSDL::Instance().KeyDown(SDL_SCANCODE_ESCAPE))
	{
		MenuActive=true;
		activeMenu=PROMT_PAUSE;
	}
}

void GameHandler::MenuInput()
{
	switch (activeMenu)
	{
	case PROMT_NEWGAME:
		if(InputManagerSDL::Instance().KeyDown(SDL_SCANCODE_SPACE))
		{
			MenuActive=false;
		}
		else if(InputManagerSDL::Instance().KeyDown(SDL_SCANCODE_ESCAPE))
		{
			gameOver=true;
		}
		break;
	case PROMT_PAUSE:
		if(InputManagerSDL::Instance().KeyDown(SDL_SCANCODE_Y))
		{
			activeMenu=PROMT_NEWGAME;
		}
		else if(InputManagerSDL::Instance().KeyDown(SDL_SCANCODE_N))
		{
			MenuActive=false;
		}
		break;
	case PROMT_GAMEOVER:
		if(InputManagerSDL::Instance().KeyDown(SDL_SCANCODE_SPACE))
		{
			CurrentRound=std::unique_ptr<Round>(new Round());
			MenuActive=false;
		}
		else if(InputManagerSDL::Instance().KeyDown(SDL_SCANCODE_ESCAPE))
		{
			gameOver=true;
		}
		break;
	default:
		break;
	}
}





