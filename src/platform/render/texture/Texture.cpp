#include "Texture.hpp"

namespace SDLGame
{
	void Texture::free()
	{
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}