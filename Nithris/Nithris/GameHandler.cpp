#include "GameHandler.h"

void GameHandler::initGame()
{
	//Sets up a new render and initializes it
	gameRender=std::unique_ptr<Render>(new Render());
	gameRender->renderInit();
	//Initialize our first round
	CurrentRound = std::unique_ptr<Round>(new Round());
	//Set up core gameplayvalues
	RequestedDirection=EDIR_NOCHANGE;
	activeMenu=PROMT_NEWGAME;
	MenuActive=true;
	gameOver=false;
	//Timers
	inputTimer.SetUpdatesPerInterval(1000);
	updateTimer.SetUpdatesPerInterval(100);
	MovementTickTimer.SetUpdatesPerInterval(StartDropSpeed);
	
}
void GameHandler::runGame()
{
	//Timer for Checking for input
	//Start the timers
	inputTimer.Start();
	updateTimer.Start();
	MovementTickTimer.Start();
	//if game is not over we run an infinite loop
	while(!gameOver)
	{
		//Is it time for dropping the piece and there is no menu open
		if(MovementTickTimer.IsTimeForUpdate() && !MenuActive)
		{
			movePiece(EDIR_DROP);
			//reset requested direction
			RequestedDirection=EDIR_NOCHANGE;
			//Process the playboard(check for complete lines)
			processPlayboard();
		}
		//Check if its time to render and move the piece horizontaly/rotate/
		if(updateTimer.IsTimeForUpdate())
		{
			//if the menu is not active move the piece and reset the requested direction
			if(!MenuActive)
			{
				movePiece(RequestedDirection);
				RequestedDirection=EDIR_NOCHANGE;
			}
			//Render the elements
			renderPlayboard();
			renderScoreBoard();
			gameRender->DrawPiece(*CurrentRound->getCurrentPiece().get(),&CurrentRound->getCurrentPiece()->piecePosition);
			//Show the menu
			if(MenuActive)
			{
				gameRender->promtUser(activeMenu);
			}
			//Flip our buffers, blitting the backbuffer to the screen
			gameRender->flipBuffers();
		}

		InputManagerSDL::Instance().Update();
		//Input
		if(!MenuActive)
		{
		//
			/*Process gameplay input, the reason why why check the input and save the desired action is that the
			threshold for pressing the key excatly on the update is lower, but we want to keep the actual moving of the element
			much slower than the fetching of the input*/
			GamePlayInput();
			//check if game over (piece at the upper rows)
			if(CurrentRound->getPlayboard()->checkGameOver())
			{
				activeMenu=PROMT_GAMEOVER;
				MenuActive=true;
			}
		}
		else
		{
			//Handle menu input
			MenuInput();
		}
		//check if window X has been pressed independantly if a menu promt is open or not
		if(InputManagerSDL::Instance().userExit())
		{
			gameOver=true;
		}

		//put the program/thread to sleep so we dont use 100% cpu powwwwaaaaahhhh!
		inputTimer.SleepUntilUpdate();
	}

}

void GameHandler::cleanUpGame()
{
	/* to be honest, i thought the uniquepointers would handle the destruction of the pointers 
	themselves but, if these are not included, the program crashes*/

	gameRender.release();
	CurrentPiece.release();
	CurrentRound.release();
}

void GameHandler::renderPlayboard()
{
	//renders the playboard
	gameRender->renderPlayBoard(CurrentRound->getPlayboard());
}

void GameHandler::renderScoreBoard()
{
	//renders the scoreboard
	gameRender->renderScoreBoard(*CurrentRound->getNextPiece().get(),CurrentRound->score,50);
}

void GameHandler::processPlayboard()
{
	//process the playboard, adding score and and updating dropspeed
	bool hasRowsBeenRemoved=CurrentRound->getPlayboard()->checkBoard();
	if(hasRowsBeenRemoved)
	{
		CurrentRound->score+=10;
		CurrentRound->dropSpeed+=.3;
		MovementTickTimer.SetUpdatesPerInterval(CurrentRound->dropSpeed);
		MovementTickTimer.Start();
	}
}


void GameHandler::movePiece(EMovement wantedMove)
{
	//if we have requested a move, as this is called each update but we dont nessecary want to move each update
	if(wantedMove!=EDIR_NOCHANGE)
	{
		//create a ghost at the new position/and or orientation and check for collision on it
		std::shared_ptr<Piece> ghost = CurrentRound->getCurrentPiece()->CreateGhost(wantedMove);
		ECollisionType collisionType = checkCollision(ghost,wantedMove);
		if(!collisionType)
		{
			//no collision occured drop the piece down
			CurrentRound->setCurrentPiece(ghost);
				
		} 
		else if(collisionType==ECT_BRICK)
		{
			//if we collided copy to playboard
			//set a new piece and generate the next one
			//reset out droptimer (if drop was used)
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
	//check each tile in the piece for collision against the playboard
	//we also have a wall option which does not invoke a copying the playboard but
	//does not allow movement to the wanted area.
	for (int y=0; y<4; y++)
	{
		for(int x=0; x<4; x++)
		{
			if(piece->tileAt(x,y))
			{
				//if outside the playarea
				if(piece->piecePosition.X+x<0 || piece->piecePosition.X+x>playboardTilesWidth-1)
				{
					return ECT_WALL;
				}
				//We split this into several ifs making it easier to read, eventough the return the same value
				//if we hit the bottom
				else if(piece->piecePosition.Y+y>playboardTilesHeight-1)
				{
					return ECT_BRICK;
				}
				//if collided on top of other brick
				else if(CurrentRound->getPlayboard()->colorOfTileAt(piece->piecePosition.X+x,piece->piecePosition.Y+y)>0 && wantedMove==EDIR_DROP)
				{
					return ECT_BRICK;
				}
				//if collided with side of other brick
				else if(CurrentRound->getPlayboard()->colorOfTileAt(piece->piecePosition.X+x,piece->piecePosition.Y+y)>0 && (wantedMove==EDIR_LEFT || wantedMove==EDIR_RIGHT || wantedMove==EDIR_ROTATE))
				{
					return ECT_WALL;
				}
				
			}
			
		}
	}
	//if no collision, ECT_None=0=false;
	return ECT_NONE;
}

//Split gameinput into to methods making it a little easier to read raither than one big input part directly in the gameloop
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
	//If the down button pressed, speed up the time effectivly dropping the piece
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
	//switch the different menu promts
	//check for input on them as they are different
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
			//new game selected create a new round.. The old uniquepointer is replaced and the references is not used therefor the unique_pointer should be deallocated
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
