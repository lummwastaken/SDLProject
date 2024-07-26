#include "Texture.hpp"

namespace SDLGame
{
	void Texture::free()
	{
		if (mTexture != NULL)
		{
			mTexture = NULL;
		}
		mWidth = 0;
		mHeight = 0;
	}
}