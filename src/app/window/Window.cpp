#include "Window.hpp"

namespace SDLGame
{
	Window::Window(const WindowData& data) :
		mWindow(NULL),
		mData(data)
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
			// renderer initialization
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

			}
		}
	}

	void Window::render()
	{

	}
	
	void Window::shutdown()
	{
		SDL_DestroyWindow(mWindow);
		mWindow = NULL;
	}
}