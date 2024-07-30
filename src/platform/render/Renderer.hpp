#pragma once

#include <SDL_render.h>
#include "Texture.hpp"

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

		SDL_Renderer* getRenderer() { return mRenderer; }
	private:
		SDL_Renderer* mRenderer;
	};
}