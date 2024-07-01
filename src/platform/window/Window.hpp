#pragma once

#include <SDL_video.h>

#include "Types.hpp"
#include "Renderer.hpp"

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

		SDL_Window* getWindow() { return mWindow; }
	private:
		SDL_Window* mWindow;

		Renderer mRenderer;
	};
}