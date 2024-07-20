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

	void Window::init(const char* title, u32 x, u32 y, u16 w, u16 h, u32 flags)
	{
		mWindow = SDL_CreateWindow(title, x, y, w, h, flags);
		if (mWindow == NULL)
		{
			destroy();
		}
		mRenderer->init(mWindow, SDL_RENDERER_ACCELERATED);
	}

	void Window::render()
	{
		mRenderer->renderFlush();
		mRenderer->renderPresent();
	}

	void Window::destroy()
	{
		mRenderer->destroy();

		SDL_DestroyWindow(mWindow);
		mWindow = NULL;
	}
}