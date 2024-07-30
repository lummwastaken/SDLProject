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
				mTexture.loadFromFile(mRenderer, "../resources/assets/textures/atlas.png");
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
		SDL_RenderClear(mRenderer);
		SDL_SetRenderDrawColor(mRenderer, 0xff, 0xff, 0xff, 0xff);
		mTexture.render(mRenderer, (640 - mTexture.getWidth()) / 2, (480 - mTexture.getHeight()) / 2);
		SDL_RenderPresent(mRenderer);
	}

	void RenderWindow::cleanup()
	{
		mTexture.free();
		SDL_DestroyRenderer(mRenderer);
		mRenderer = NULL;
		SDL_DestroyWindow(mWindow);
		mWindow = NULL;
	}
}