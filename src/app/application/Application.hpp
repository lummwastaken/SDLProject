#pragma once

#include "RenderWindow.hpp"

#define APP_INIT SDLGame::Application::instance()->init();
#define APP_RUNLOOP SDLGame::Application::instance()->runLoop();

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

namespace SDLGame
{
	class Application
	{
	public:
		Application(Application const&) = delete;
		Application& operator = (Application const&) = delete;

		static std::shared_ptr<Application> instance()
		{
			static std::shared_ptr<Application> appPtr{ new Application };
			return appPtr;
		}

		void init();

		void runLoop();

	private:
		Application()
		{
		}

		void shutdown();

		std::unique_ptr<RenderWindow> mainWin = std::make_unique<RenderWindow>();
	};
}