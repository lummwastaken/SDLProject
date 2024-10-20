#include "Window.hpp"

namespace SDLGame
{
	Window::Window() :
		mWindow(NULL),
		mRenderer(NULL)
	{
	}

	bool Window::init(const char* title, u32 width, u32 height)
	{
		mWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
		if (mWindow != NULL)
		{
			LOG_TRACE("SDL Window created with title: {}", title);
			mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
			if (mRenderer != NULL)
			{
				LOG_TRACE("SDL Renderer created for window: {}", title);
			}
			else
			{
				LOG_ERROR("Failed to create renderer for window: {}! SDL Error: {}", title, SDL_GetError());
				return false;
			}
		}
		else
		{
			LOG_ERROR("Failed to create window with title: {}! SDL Error: {}", title, SDL_GetError());
			return false;
		}
		return true;
	}

	void Window::shutdown()
	{
		SDL_DestroyRenderer(mRenderer);
		mRenderer = NULL;
		SDL_DestroyWindow(mWindow);
		mWindow = NULL;
	}
}