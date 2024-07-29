#pragma once

#include <SDL_render.h>

namespace SDLGame
{
	class Renderer
	{
	public:
		Renderer()
			: mRenderer(NULL)
		{
		}

		bool init(SDL_Window* win, u32 flags);

		void renderFrame();

		void destroy();
	private:
		SDL_Renderer* mRenderer;
	};
}