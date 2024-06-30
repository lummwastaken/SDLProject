#include "Window.hpp"

namespace SDLGame 
{
	Window::Window() 
		: mWindow(NULL), 
		mRenderer(NULL)
	{
	}

	Window::~Window() 
	{
		shutdown();
	}

	void Window::init(const char* t, u32 x, u32 y, u16 w, u16 h, u32 flags)
	{
		mWindow = SDL_CreateWindow(t, x, y, w, h, flags);
		if (mWindow == NULL)
		{
			shutdown();
		}
		else {
			mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
			if (mRenderer == NULL)
			{
				shutdown();
			}
		}
	}

	void Window::update()
	{
		SDL_RenderClear(mRenderer);
		SDL_SetRenderDrawColor(mRenderer, 0xff, 0xff, 0xff, 0xff);
		SDL_RenderPresent(mRenderer);
	}

	void Window::shutdown()
	{
		SDL_DestroyRenderer(mRenderer);
		mRenderer = NULL;
		SDL_DestroyWindow(mWindow);
		mWindow = NULL;
	}
}