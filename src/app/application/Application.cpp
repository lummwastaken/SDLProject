#include "Application.hpp"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "Timer.hpp"

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

	void Application::loadResources()
	{
		mTex.loadFromFile(mainWin->getRenderer(), "../resources/assets/textures/water.png");
	}

	void Application::runLoop()
	{
		bool isRunning = true;

		SDL_Event event;

		Timer inputTimer;
		inputTimer.start();

		while (isRunning)
		{
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					isRunning = false;
				}
				else if (event.type == SDL_KEYDOWN)
				{
					switch (event.key.keysym.sym)
					{
					case SDLK_w:
						LOG_INFO("Recieved input 'W' after {} ticks!", inputTimer.getTicks());
						break;
					case SDLK_a:
						LOG_INFO("Recieved input 'A' after {} ticks!", inputTimer.getTicks());
						break;
					case SDLK_s:
						LOG_INFO("Recieved input 'S' after {} ticks!", inputTimer.getTicks());
						break;
					case SDLK_d:
						LOG_INFO("Recieved input 'D' after {} ticks!", inputTimer.getTicks());
						break;
					default:
						break;
					}
				}
			}
			mainWin->renderFlush();
			mTex.render(
				mainWin->getRenderer(),
				(SCREEN_WIDTH - mTex.getWidth()) / 2,
				(SCREEN_HEIGHT - mTex.getHeight()) / 2
				);
			mainWin->renderPresent();
		}
	}

	void Application::shutdown()
	{
		Logger::quit();
		IMG_Quit();
		Mix_Quit();
		SDL_Quit();
	}
}