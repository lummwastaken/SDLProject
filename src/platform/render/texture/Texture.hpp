#pragma once

#include "SDL_image.h"
#include "Types.hpp"

namespace SDLGame
{
	class Texture
	{
	public:
		Texture() { free(); }
		~Texture() { free(); }

		void free();
	private:
		SDL_Texture* mTexture;
		int mWidth, mHeight;
	};
}