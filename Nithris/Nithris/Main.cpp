#include <SDL.h>
#include "GameHandler.h"
#include <iostream>

int main( int argc,char* argv[] ) 
{
	try{
		GameHandler::instance().initGame();
	}
	catch(GraphicsInitEx ex){
		std::cout<<ex.what()<<std::endl;
		return 1;
	}
	GameHandler::instance().runGame();
	GameHandler::instance().cleanUpGame();
	return 0;  // Ok.
}  // END main