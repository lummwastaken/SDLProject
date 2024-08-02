#include "Application.hpp"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

namespace SDLGame
{
	void Application::init()
	{
		Logger::init();

		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS) > 0)
		{
			LOG_CRASH("Could not initialize SDL! SDL Error: {}", SDL_GetError());
		}
		else
		{
			if (!(IMG_Init(IMG_INIT_PNG)))
			{
				LOG_CRASH("Could not initialize SDL_image! SDL_image Error: {}", IMG_GetError());
			}
			else
			{
				if (!(Mix_Init(MIX_INIT_OGG)))
				{
					LOG_CRASH("Could not initialize SDL_mixer! SDL_mixer Error: {}", Mix_GetError());
				}
				else
				{
					mainWin->init("Test Window", SCREEN_WIDTH, SCREEN_HEIGHT);
					LOG_INFO("Created window with resolution: {}x{} and title: {}", mainWin->getWidth(), mainWin->getHeight(), mainWin->getTitle());
				}
			}
		}
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
				mainWin->update();
			}
		}
		shutdown();
	}

	void Application::shutdown()
	{
		Logger::quit();
		IMG_Quit();
		Mix_Quit();
		SDL_Quit();
	}
}