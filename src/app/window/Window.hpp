#pragma once

#include "SDL_video.h"
#include "SDL_render.h"

namespace SDLGame 
{
	class Window
	{
	public:
		Window();

		bool init(const char* title, u32 width, u32 height);

		void shutdown();
	private:
		SDL_Window* mWindow;
		SDL_Renderer* mRenderer;
	};
}