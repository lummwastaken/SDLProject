#include "Renderer.hpp"

namespace SDLGame
{
	bool Renderer::init(SDL_Window* win, u32 flags)
	{
		mRenderer = SDL_CreateRenderer(win, -1, flags);
		return mRenderer != NULL;
	}

	void Renderer::renderFlush()
	{
		SDL_RenderClear(mRenderer);
		SDL_SetRenderDrawColor(mRenderer, 0xff, 0xff, 0xff, 0xff);
	}

	void Renderer::renderPresent()
	{
		SDL_RenderPresent(mRenderer);
	}
}