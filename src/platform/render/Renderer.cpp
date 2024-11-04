#include "Renderer.hpp"

namespace SDLGame
{
	bool Renderer::init(SDL_Window* const& window)
	{
		mRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (mRenderer == NULL)
		{
			LOG_ERROR("Failed to create SDL Renderer! SDL Error: {}", SDL_GetError());
			return false;
		}
		return true;
	}

	void Renderer::draw()
	{
		SDL_RenderClear(mRenderer);
		SDL_SetRenderDrawColor(mRenderer, 0xff, 0xff, 0xff, 0xff);
		SDL_RenderPresent(mRenderer);
	}

	void Renderer::shutdown()
	{
		SDL_DestroyRenderer(mRenderer);
		mRenderer == NULL;
	}
}