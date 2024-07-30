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

	bool Texture::loadFromFile(SDL_Renderer* rend, str path)
	{
		free();

		SDL_Surface* loadSurface = IMG_Load(path.c_str());
		if (loadSurface != NULL)
		{
			SDL_SetColorKey(loadSurface, SDL_TRUE, SDL_MapRGB(loadSurface->format, 0xff, 0xff, 0xff));

			mTexture = SDL_CreateTextureFromSurface(rend, loadSurface);
			if (mTexture != NULL)
			{
				mWidth = loadSurface->w;
				mHeight = loadSurface->h;
			}
			else
			{
				LOG_ERROR("Unable to create texture from image: {}! SDL Error: {}", path.c_str(), SDL_GetError());
			}
			SDL_FreeSurface(loadSurface);
		}
		else
		{
			LOG_ERROR("Unable to load image: {}! SDL_image Error: {}", path.c_str(), SDL_GetError());
		}

		return mTexture != NULL;
	}

	void Texture::render(SDL_Renderer* rend, int x, int y, SDL_Rect* clip, f64 angle, SDL_Point* pivot, SDL_RendererFlip flip)
	{
		SDL_Rect renderQuad = { x, y, mWidth, mHeight };

		if (clip != NULL)
		{
			renderQuad.w = clip->w;
			renderQuad.h = clip->h;
		}

		if (SDL_RenderCopyEx(rend, mTexture, clip, &renderQuad, angle, pivot, flip) < 0)
		{
			LOG_ERROR("Failed to render texture! SDL Error: {}", SDL_GetError());
		}
	}
}