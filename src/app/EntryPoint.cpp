#include <SDL_main.h>

#include "Application.hpp"

int main(int argc, char* argv[]) 
{
	std::shared_ptr<SDLGame::Application> mainApp = SDLGame::Application::instance();

	if (mainApp->init())
	{
		mainApp->runLoop();
	}
	mainApp->shutdown();

	return 0;
} 