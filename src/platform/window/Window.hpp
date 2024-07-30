#pragma once

#include <SDL_video.h>
#include <SDL_render.h>

namespace SDLGame 
{
	class Window 
	{
	public:
		Window() {
			mData = { NULL, NULL, NULL };
		}

		~Window() {}

		virtual void init(const char* title, u16 w, u16 h) = 0;

		virtual void update() = 0;

		virtual void cleanup() = 0;

		u16 getWidth() { return mData.width; }
		u16 getHeight() { return mData.height; }
		const char* getTitle() { return mData.title; }

	protected:
		struct winData
		{
			const char* title;
			u16 width, height;
		};

		winData mData;
	};
}