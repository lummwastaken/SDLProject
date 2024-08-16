#include <SDL_main.h>

#include "Application.hpp"

int main(int argc, char* argv[]) 
{
	APP_INIT;
	APP_LOAD;
	APP_RUNLOOP;
	APP_SHUTDOWN;
	return 0;
} 