#include "Application.hpp"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "Logger.hpp"

namespace SDLGame
{
	bool Application::initSubSystems()
	{
		Logger::init();
		bool success = true;
		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
		{
			success = false;
			LOG_ERROR("Could not initialize SDL!");
			shutdown();
		}
		else
		{
			if (IMG_Init(IMG_INIT_PNG) < 0)
			{
				success = false;
				LOG_ERROR("Could not initialize SDL_image!");
				shutdown();
			}
			else
			{
				if (Mix_Init(MIX_INIT_OGG) < 0)
				{
					success = false;
					LOG_ERROR("Could not initialize SDL_mixer!");
					shutdown();
				}
			}
		}

		return success;
	}

	bool Application::initObjects()
	{
		if (mWindow->init(
			"Test Window", 
			SDL_WINDOWPOS_UNDEFINED, 
			SDL_WINDOWPOS_UNDEFINED, 
			640, 480, 
			0
		))
		{
			return true;
		}
		return false;
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
		LOG_INFO("Shutting down...");
		mWindow->destroy();

		Logger::quit();
		IMG_Quit();
		Mix_Quit();
		SDL_Quit();
	}
}