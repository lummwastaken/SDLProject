#include "Renderer.hpp"

namespace SDLGame
{
	bool Renderer::init(SDL_Window* win, u32 flags)
	{
		mRenderer = SDL_CreateRenderer(win, -1, flags);
		if (mRenderer == NULL)
		{
			LOG_ERROR("Could not create renderer! SDL Error: %s", SDL_GetError());
			destroy();
		}
		return mRenderer != NULL;
	}

	void Renderer::renderFrame()
	{
		SDL_RenderClear(mRenderer);
		SDL_SetRenderDrawColor(mRenderer, 0xff, 0xff, 0xff, 0xff);
		SDL_RenderPresent(mRenderer);
	}

	void Renderer::destroy()
	{
		SDL_DestroyRenderer(mRenderer);
		mRenderer = NULL;
	}
}