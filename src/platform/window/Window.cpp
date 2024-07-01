#include "Window.hpp"

namespace SDLGame 
{
	Window::Window() 
		: mWindow(NULL)
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
		else
		{
			if (!mRenderer.init(mWindow, 0))
			{
				shutdown();
			}
		}
	}

	void Window::update()
	{
		mRenderer.renderFlush();
		mRenderer.renderPresent();
	}

	void Window::shutdown()
	{
		SDL_DestroyWindow(mWindow);
		mWindow = NULL;
	}
}