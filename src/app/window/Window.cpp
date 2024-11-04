#include "Window.hpp"

namespace SDLGame
{
	Window::Window(const WindowData& data) :
		mWindow(NULL),
		mData(data),
		mMinimized(false)
	{
	}

	bool Window::init()
	{
		mWindow = SDL_CreateWindow(
			mData.title, 
			SDL_WINDOWPOS_UNDEFINED, 
			SDL_WINDOWPOS_UNDEFINED, 
			mData.width, 
			mData.height, 
			mData.flags
		);
		if (mWindow != NULL)
		{
			if (!(*mRenderer).init(mWindow))
			{
				LOG_ERROR("Failed to create renderer for window: {}", mData.title);
				return false;
			}
		}
		else
		{
			LOG_ERROR("Failed to create window with title: {}! SDL Error: {}", mData.title, SDL_GetError());
			return false;
		}
		return true;
	}

	void Window::handleEvent(const SDL_Event& e)
	{
		if (e.type == SDL_WINDOWEVENT)
		{
			switch (e.window.event)
			{
			case SDL_WINDOWEVENT_MINIMIZED:
				mMinimized = true;
				break;
			case SDL_WINDOWEVENT_MAXIMIZED:
				mMinimized = false;
				break;
			case SDL_WINDOWEVENT_RESTORED:
				mMinimized = false;
				break;
			}
		}
	}

	void Window::render()
	{
		if (!mMinimized)
		{
			(*mRenderer).draw();
		}
	}
	
	void Window::shutdown()
	{
		(*mRenderer).shutdown();

		SDL_DestroyWindow(mWindow);
		mWindow = NULL;
	}
}