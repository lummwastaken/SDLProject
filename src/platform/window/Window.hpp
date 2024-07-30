#pragma once

#include <SDL_video.h>

#include "Renderer.hpp"

namespace SDLGame 
{
	class Window 
	{
	public:
		Window();
		~Window();

		bool init (const char* title, u16 w, u16 h);

		void render();

		void destroy();

	private:
		SDL_Window* mWindow;

		std::unique_ptr<Renderer> mRenderer = std::make_unique<Renderer>();
	};
}