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

		~RenderWindow() override { cleanup(); }

		void RenderWindow::init(const char* title, int w, int h);

		void RenderWindow::cleanup();
	private:
		SDL_Window* mWindow;
		SDL_Renderer* mRenderer;
	};
}