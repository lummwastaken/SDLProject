#include "Window.hpp"

namespace SDLGame 
{
	Window::Window() 
		: mWindow(NULL)
	{
	}

	Window::~Window() 
	{
		destroy();
	}

	bool Window::init(const char* title, u16 w, u16 h)
	{
		mWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, 0);
		if (mWindow != NULL)
		{
			LOG_TRACE("Successfully initialized Window");
		}
		else
		{
			LOG_ERROR("Could not create window! SDL Error: {}", SDL_GetError());
			destroy();
		}
		return mWindow != NULL && mRenderer->init(mWindow, SDL_RENDERER_ACCELERATED);
	}

	void Window::render()
	{
		mRenderer->renderFrame();
	}

	void Window::destroy()
	{
		mRenderer->destroy();

		SDL_DestroyWindow(mWindow);
		mWindow = NULL;
	}
}