#include "Application.hpp"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

namespace SDLGame
{
	bool Application::init()
	{
		Logger::init();
		bool success = true;
		// Initialize Subsystems
		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS) < 0)
		{
			LOG_CRASH("Could not initialize SDL! SDL Error: {}", SDL_GetError());
			success = false;
		}
		else
		{
			if (IMG_Init(IMG_INIT_PNG) < 0)
			{
				LOG_CRASH("Could not initialize SDL_image! SDL_image Error: {}", IMG_GetError());
				success = false;
			}
			else
			{
				if (Mix_Init(MIX_INIT_OGG) < 0)
				{
					LOG_CRASH("Could not initialize SDL_mixer! SDL_mixer Error: {}", Mix_GetError());
					success = false;
				}
			}
		}
		// Initialize Objects
		if (!mainWindow->init("Test Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0))
		{
			success = false;
		}
		return success;
	}

	bool Application::loadMedia()
	{
		bool success = true;
		return success;
	}

	void Application::runLoop()
	{
		bool isRunning = true;

		SDL_Event event;

		while (isRunning)
		{
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					isRunning = false;
				}
			}
			mainWindow->render();
		}
		shutdown();
	}

	void Application::shutdown()
	{
		mainWindow->destroy();

		Logger::quit();
		IMG_Quit();
		Mix_Quit();
		SDL_Quit();
	}
}