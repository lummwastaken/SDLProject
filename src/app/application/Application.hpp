#pragma once

#include "RenderWindow.hpp"

#define INIT SDLGame::Application::instance()->init();
#define RUNLOOP SDLGame::Application::instance()->runLoop();

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