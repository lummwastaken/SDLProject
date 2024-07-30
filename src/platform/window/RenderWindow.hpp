#pragma once

#include "Window.hpp"

namespace SDLGame
{
	class RenderWindow : public Window
	{
	public:
		RenderWindow() :
			mWindow(NULL),
			mRenderer(NULL)
		{
		}

		~RenderWindow() { cleanup(); }

		void init(const char* title, int w, int h) override;

		void update() override;

		void cleanup() override;
	private:
		SDL_Window* mWindow;
		SDL_Renderer* mRenderer;
	};
}