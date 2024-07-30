#pragma once

#include <SDL_video.h>
#include <SDL_render.h>

namespace SDLGame 
{
	class Window 
	{
	public:
		Window();
		~Window();

		virtual void init (const char* title, u16 w, u16 h);

		virtual void render();

		virtual void cleanup();

	private:
		SDL_Window* mWindow;
		SDL_Renderer* mRenderer;
	};
}