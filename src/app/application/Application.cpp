#include "Application.hpp"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

namespace SDLGame
{
	bool Application::initSubSystems()
	{
		bool success = true;
		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
		{
			success = false;
			shutdown();
		}
		else
		{
			if (IMG_Init(IMG_INIT_PNG) < 0)
			{
				success = false;
				shutdown();
			}
			else
			{
				if (Mix_Init(MIX_INIT_OGG) < 0)
				{
					success = false;
					shutdown();
				}
			}
		}
		return success;
	}

	void Application::initObjects()
	{
		mWindow->init("Test Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
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
			mWindow->render();
		}
		shutdown();
	}

	void Application::shutdown()
	{
		mWindow->destroy();

		IMG_Quit();
		Mix_Quit();
		SDL_Quit();
	}
}