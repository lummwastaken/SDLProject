#include <SDL_main.h>

#include "Application.hpp"

int main(int argc, char* argv[]) 
{
	SDLGame::Application mainApp;

	if (mainApp.init())
	{
		mainApp.runLoop();
	}
	mainApp.shutdown();

	return 0;
} 