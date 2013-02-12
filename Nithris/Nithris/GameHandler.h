#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H

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
private:
	GameHandler();
	GameHandler(const GameHandler)&
	GameHandler& operator=(const GameObject&);
	
	void prompUser()
};
#endif

