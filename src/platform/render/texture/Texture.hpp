#pragma once

#include <SDL_image.h>

namespace SDLGame
{
	class Texture
	{
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

		bool loadFromFile(SDL_Renderer* rend, str path);

		void render(SDL_Renderer* rend, int x = 0, int y = 0, SDL_Rect* clip = NULL, f64 angle = 0.0, f64 scale = 1.0, SDL_Point* pivot = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

		void free();

		int getWidth() { return mWidth; }
		int getHeight() { return mHeight; }

	private:
		SDL_Texture* mTexture;
		int mWidth, mHeight;
	};
}