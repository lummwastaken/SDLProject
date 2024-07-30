#include "Texture.hpp"

namespace SDLGame
{
	void Texture::loadFromFile(str path)
	{
		free();

		SDL_Surface* loadedSurface = IMG_Load(path.c_str());
		if (loadedSurface != NULL)
		{
			SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0xff, 0xff, 0xff));
			// extra function for renderer!
			SDL_FreeSurface(loadedSurface);
		}
		else
		{
			LOG_ERROR("Unable to load image: {}! SDL_image Error: {}", path.c_str(), IMG_GetError());
		}
	}

	void Texture::free()
	{
		if (mTexture != NULL)
		{
			SDL_DestroyTexture(mTexture);
			mTexture = NULL;
			mWidth = 0;
			mHeight = 0;
		}
	}
}