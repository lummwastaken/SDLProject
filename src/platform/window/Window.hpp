#pragma once

#include <SDL_video.h>
#include <SDL_render.h>

namespace SDLGame 
{
	class Window 
	{
	public:
		Window();

		virtual ~Window();

		virtual void init() = 0;

		virtual void render() = 0;

		virtual void cleanup() = 0;

	private:
		SDL_Window* mWindow;
		SDL_Renderer* mRenderer;
	};
}