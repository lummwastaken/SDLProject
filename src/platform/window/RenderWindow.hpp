#pragma once

#include "Window.hpp"
#include "Texture.hpp"

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

		void init(const char* title, u16 w, u16 h) override;

		void update() override;

		void cleanup() override;

		SDL_Window* getWindow() { return mWindow; }
		SDL_Renderer* getRenderer() { return mRenderer; }

	private:
		SDL_Window* mWindow;
		SDL_Renderer* mRenderer;
	};
}