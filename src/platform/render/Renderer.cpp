#include "Renderer.hpp"

namespace SDLGame
{
	void Renderer::init(SDL_Window* win, u32 flags)
	{
		mRenderer = SDL_CreateRenderer(win, -1, flags);
		if (mRenderer == NULL)
		{
			destroy();
		}
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

	void Renderer::destroy()
	{
		SDL_DestroyRenderer(mRenderer);
		mRenderer = NULL;
	}
}