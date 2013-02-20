#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H

#include <SDL.h>
#include <memory>
#include <vector>

#include "Render.h"
#include "GraphicsInitEx.h"
#include "NithrisConstants.h"

class GameHandler
{
public:
	static GameHandler& instance()
	{
		static GameHandler gh;
		return gh;
	}
	void initGame();
	void runGame();
	void cleanUpGame();
	std::shared_ptr<SDL_Texture> getAsset(ETexture requestedAsset);
private:
	GameHandler();
	GameHandler(const GameHandler&);
	GameHandler& operator=(const GameHandler&);
	
	void prompUser();
	void renderPlayboard();
	void renderScoreBoard();
	void processPlayboard();
	void startNewGame();
	void getNewPiece();
	void moveCurrentPiece();
	std::shared_ptr<SDL_Texture> LoadAsset(const char* filename);
	std::unique_ptr<Render> gameRender;
	std::vector<std::shared_ptr<SDL_Texture>> Content;
};

#endif

