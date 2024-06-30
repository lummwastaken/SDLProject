#include <SDL.h>
#include "Application.hpp"

std::shared_ptr<SDLGame::Application> gameApp = gameApp->instance();

int main(int argc, char* argv[]) 
{
	if (!gameApp->initSubSystems())
	{
		//error here
		return 0;
	}
	gameApp->initObjects();
	gameApp->runLoop();
	return 0;
}