#include "Application.hpp"

#include <spdlog/spdlog.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_thread.h>

namespace SDLGame
{
	bool Application::init()
	{
		Logger::init(spdlog::level::trace);

		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS) > 0)
		{
			LOG_CRASH("Could not initialize SDL! SDL Error: {}", SDL_GetError());
			return false;
		}
		else
		{
			if (!(IMG_Init(IMG_INIT_PNG)))
			{
				LOG_CRASH("Could not initialize SDL_image! SDL_image Error: {}", IMG_GetError());
				return false;
			}
			else
			{
				if (!(Mix_Init(MIX_INIT_OGG)))
				{
					LOG_CRASH("Could not initialize SDL_mixer! SDL_mixer Error: {}", Mix_GetError());
					return false;
				}
				else
				{
					if (!(*mWindow).init())
					{
						LOG_CRASH("Failed to initialize window! Shutting down...");
						return false;
					}
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

				(*mWindow).handleEvent(event);
			}

			(*mWindow).render();
		}
	}

	void Application::shutdown()
	{
		(*mWindow).shutdown();
		Logger::quit();
		IMG_Quit();
		Mix_Quit();
		SDL_Quit();
	}
}