#include "Window.hpp"
#include "Logger.hpp"

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

	bool Window::init(const char* title, u32 x, u32 y, u16 w, u16 h, u32 flags)
	{
		mWindow = SDL_CreateWindow(title, x, y, w, h, flags);
		if (mWindow == NULL)
		{
			LOG_ERROR("Could not create window! SDL Error: {}", SDL_GetError());
			destroy();
		}
		return mWindow != NULL && mRenderer->init(mWindow, SDL_RENDERER_ACCELERATED);
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