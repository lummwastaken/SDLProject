#pragma once

#include "RenderWindow.hpp"

#define APP_INIT SDLGame::Application::instance()->init();
#define APP_RUNLOOP SDLGame::Application::instance()->runLoop();
#define APP_SHUTDOWN SDLGame::Application::instance()->shutdown();

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

		void shutdown();

	private:
		Application() {}

		Texture mTex;

		std::unique_ptr<RenderWindow> mainWin = std::make_unique<RenderWindow>();
	};
}