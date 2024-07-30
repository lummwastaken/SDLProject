#pragma once

#include "Window.hpp"

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

		bool init();

		void runLoop();

	private:
		Application() {}

		void shutdown();

		std::unique_ptr<Window> mainWindow = std::make_unique<Window>();
	};
}