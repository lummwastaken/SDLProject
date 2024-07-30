#pragma once

#include <SDL_video.h>
#include <SDL_render.h>

namespace SDLGame 
{
	struct winData
	{
		const char* title;
		u16 width, height;
	};

	class Window 
	{
	public:
		Window() {}

		~Window() {}

		virtual void init(const char* title, u16 w, u16 h) = 0;

		virtual void update() = 0;

		virtual void cleanup() = 0;

	private:
	};
}