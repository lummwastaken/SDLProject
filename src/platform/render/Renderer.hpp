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

		bool init(SDL_Window* const& window);

		void draw();

		void shutdown();
	private:
		SDL_Renderer* mRenderer;
	};
}