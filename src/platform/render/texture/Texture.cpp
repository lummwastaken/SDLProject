#include "Texture.hpp"

namespace SDLGame
{
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