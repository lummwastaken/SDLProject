#include "RenderWindow.hpp"

namespace SDLGame
{
	void RenderWindow::init(const char* title, int x, int y)
	{
		mWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, x, y, 0);
		if (mWindow != NULL)
		{
			LOG_TRACE("Successfully initialized Window!");
			mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
			if (mRenderer != NULL)
			{
				LOG_TRACE("Successfully initialized Renderer!");
			}
			else
			{
				LOG_ERROR("Failed to create renderer for window! SDL Error: {}", SDL_GetError());
			}
		}
		else
		{
			LOG_ERROR("Failed to create window! SDL Error: {}", SDL_GetError());
		}
	}

	void RenderWindow::update()
	{
		SDL_SetRenderDrawColor(mRenderer, 0xff, 0xff, 0xff, 0xff);
		SDL_RenderClear(mRenderer);
		SDL_RenderPresent(mRenderer);
	}

	void RenderWindow::cleanup()
	{
		SDL_DestroyRenderer(mRenderer);
		mRenderer = NULL;
		SDL_DestroyWindow(mWindow);
		mWindow = NULL;
	}
}