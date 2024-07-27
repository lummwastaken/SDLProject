#pragma once

#include <SDL_video.h>

#include "Types.hpp"
#include "Renderer.hpp"

namespace SDLGame 
{
	class Window 
	{
	public:
		Window();
		~Window();

		bool init (const char* title, u32 x, u32 y, u16 w, u16 h, u32 flags);

		void render();

		void destroy();

		SDL_Window* getWindow() { return mWindow; }
	private:
		SDL_Window* mWindow;

		std::unique_ptr<Renderer> mRenderer = std::make_unique<Renderer>();
	};
}