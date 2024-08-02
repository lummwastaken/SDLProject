#include <SDL_main.h>

#include "Application.hpp"

std::shared_ptr<SDLGame::Application> gameApp = gameApp->instance();

int main(int argc, char* argv[]) 
{
	INIT;
	RUNLOOP;
	return 0;
}