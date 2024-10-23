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
		std::unique_ptr<Window> mWindow = std::make_unique<Window>();
	};
}