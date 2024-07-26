#pragma once

#include "SDL_image.h"
#include "Types.hpp"

namespace SDLGame
{
	class Texture
	{
	public:
		Texture() : 
			mTexture(NULL),
			mWidth(0),
			mHeight(0)
		{
		}

		~Texture() { free(); }

		void free();

		int getWidth() { return mWidth; }
		int getHeight() { return mHeight; }
	private:
		SDL_Texture* mTexture;
		int mWidth, mHeight;
	};
}