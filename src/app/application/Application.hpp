#pragma once

#include "window/Window.hpp"

namespace SDLGame
{
	class Application
	{
	public:
		bool init();

		void runLoop();

		void shutdown();

	private:
		WindowData initData = {
			"SDL Game Window", 
			640, 
			480, 
			0
		};
		std::unique_ptr<Window> mWindow = std::make_unique<Window>(initData);
	};
}