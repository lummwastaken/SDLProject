#include "RenderWindow.hpp"

namespace SDLGame
{
	void RenderWindow::init(const char* title, u16 w, u16 h)
	{
		mData = { title, w, h };
		mWindow = SDL_CreateWindow(
			mData.title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
			mData.width, mData.height, 
			0
		);
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

	void RenderWindow::renderFlush()
	{
		SDL_RenderClear(mRenderer);
		SDL_SetRenderDrawColor(mRenderer, 0xff, 0xff, 0xff, 0xff);
	}

	void RenderWindow::renderPresent()
	{
		SDL_RenderPresent(mRenderer);
	}

	void RenderWindow::update()
	{

	}

	void RenderWindow::cleanup()
	{
		SDL_DestroyRenderer(mRenderer);
		mRenderer = NULL;
		SDL_DestroyWindow(mWindow);
		mWindow = NULL;
	}
}