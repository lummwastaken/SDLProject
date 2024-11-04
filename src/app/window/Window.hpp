#pragma once

#include "SDL_video.h"
#include "SDL_render.h"
#include "SDL_events.h"

#include "Renderer.hpp"

namespace SDLGame 
{
	struct WindowData
	{
		const char* title = "Test Window";
		u32 width = 640, height = 480;
		u32 flags = 0;
	};

	class Window
	{
	public:
		Window(const WindowData& data);

		bool init();

		void handleEvent(const SDL_Event& e);

		void render();

		void shutdown();
	private:
		SDL_Window* mWindow;
		WindowData mData;

		bool mMinimized;

		std::unique_ptr<Renderer> mRenderer = std::make_unique<Renderer>();
	};
}