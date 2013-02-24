
//PG4400 - INNLEVERING 1 - TRYM NILSEN
#include <SDL.h>
#include "GameHandler.h"
#include <iostream>

int main( int argc,char* argv[] ) 
{
	//try to initialize our game
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
/* This is elg, he hopes you have had a nice time playing
		/^\                                         /^\
		|   \_/^\                               /^\_/   |
		|        \_/^\                     /^\_/        |
		\            \_/^\           /^\_/            /
		 \__              \___---___/              __/
            ---___         /       \         ___---
				  ---___  |         |  ___---
                        --|  _   _  |--
                         |  | | | |  |
                         |  |o| |o|  |
                        /    -   -    \
                       |      ___      |
					  /     --   --     \
					 |                   |
					/                     \
					|                       |
					|                       |
					|       /\     /\       |
					\ \   |  |   |  |   / /
					/\ \   --     --   / /\
				   /  \ \_____   _____/ /  \
				  /    \__    ---    __/    \
				 /\       --__---__--       /\
				/  \/                3    \/  \
			   /   /    _S___W___F____     \   \
			  /   |             _______-----|   \
			 |    |________-----            |    |
		     |    |                         |    |
			 |    |                         |    |
			 \    \                       /    /
			  \\   \                     /   //
			   \\ \_\                   /_/ //
				  --  \                 /  --
					   |  ---_____---  |
					   |     |   |     |
					   |     |   |     |
					   |     |   |     |
					   |     |   |     |
					   / V     \ /    V  \
					   |_|_____| |____|__|
					   |_|_____| |____|__|
*/