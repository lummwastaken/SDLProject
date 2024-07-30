#pragma once

#include "Texture.hpp"

namespace SDLGame
{
	class ISprite
	{
		// Base functionality for sprites -- take a texture from memory, then clip it down to a single image, or set of frames.
	public:
	private:
		Texture mSpriteTexture;
		int mWidth, mHeight;
	};
}