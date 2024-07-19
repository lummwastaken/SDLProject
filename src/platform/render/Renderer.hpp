#pragma once

#include <SDL_render.h>

#include "Types.hpp"

namespace SDLGame
{
	class Renderer
	{
	public:
		Renderer()
			: mRenderer(NULL)
		{
		}

		void init(SDL_Window* win, u32 flags);

		void renderFlush();
		void renderPresent();

		void destroy();
	private:
		SDL_Renderer* mRenderer;
	};
}