#include <SDL_main.h>

#include "Application.hpp"

std::shared_ptr<SDLGame::Application> gameApp = gameApp->instance();

int main(int argc, char* argv[]) 
{
	if (gameApp->init())
	{
		gameApp->runLoop();
	}
	else
	{
		LOG_CRASH("Could not initialize the application!");
		return 0;
	}
	return 0;
}