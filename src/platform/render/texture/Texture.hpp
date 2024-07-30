#pragma once

#include <SDL_image.h>

namespace SDLGame
{
	class Texture
	{
		// Texture that is loaded into memory, possibly rendered
	public:
		Texture() : 
			mTexture(NULL),
			mWidth(NULL), 
			mHeight(NULL)
		{
		}

		~Texture() { free(); }

		void setColor(u8 red, u8 green, u8 blue) { SDL_SetTextureColorMod(mTexture, red, green, blue); }
		void setBlend(SDL_BlendMode blend) { SDL_SetTextureBlendMode(mTexture, blend); }
		void setAlpha(u8 alpha) { SDL_SetTextureAlphaMod(mTexture, alpha); }

		void loadFromFile(str path);

		void render(SDL_Renderer* rend);

		void free();

		int getWidth() { return mWidth; }
		int getHeight() { return mHeight; }

	private:
		SDL_Texture* mTexture;
		int mWidth, mHeight;
	};
}