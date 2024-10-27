#pragma once

#include <SDL_video.h>
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

		bool Init(SDL_Window* const& window);
	private:
		SDL_Renderer* mRenderer;
	};
}