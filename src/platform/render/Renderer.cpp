#include "Renderer.hpp"

namespace SDLGame
{
	bool Renderer::Init(SDL_Window* const& window)
	{
		mRenderer = SDL_CreateRenderer(window, -1, 0);
		if (mRenderer != NULL)
		{

		}
		else
		{
			LOG_ERROR("Failed to create SDL Renderer! SDL Error: {}", SDL_GetError());
			return false;
		}
		return true;
	}
}