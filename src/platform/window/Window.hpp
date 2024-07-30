#pragma once

#include <SDL_video.h>
#include <SDL_render.h>

namespace SDLGame 
{
	class Window 
	{
	public:
		Window() {}

		~Window() {}

		virtual void init(const char* title, int w, int h) = 0;

		virtual void update() = 0;

		virtual void cleanup() = 0;

	private:
	};
}