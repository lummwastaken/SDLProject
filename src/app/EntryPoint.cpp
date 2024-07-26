#include <SDL_main.h>
#include "Application.hpp"
#include "Logger.hpp"

#include<cassert>

std::shared_ptr<SDLGame::Application> gameApp = gameApp->instance();

int main(int argc, char* argv[]) 
{
	if (!gameApp->initSubSystems())
	{
		LOG_ERROR("Could not initialize subsystems!");
		return 0;
	}
	else 
	{
		if (!gameApp->initObjects())
		{
			LOG_ERROR("Could not initialize application!");
			return 0;
		}
	}
	gameApp->runLoop();
	return 0;
}