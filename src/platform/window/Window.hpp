#pragma once

#include <SDL_video.h>
#include <SDL_render.h>

#include "Types.hpp"

namespace SDLGame 
{
	class Window 
	{
	public:
		Window();
		~Window();

		void init (const char* t, u32 x, u32 y, u16 w, u16 h, u32 flags);

		void update();

		void shutdown();
	private:
		SDL_Window* mWindow;
		SDL_Renderer* mRenderer;
	};
}