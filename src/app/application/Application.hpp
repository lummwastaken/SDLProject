#pragma once

#include <memory>

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

		bool initSubSystems();

		bool initObjects();

		void runLoop();

	private:
		Application() {}

		void shutdown();

		std::unique_ptr<Window> mWindow = std::make_unique<Window>();
	};
}