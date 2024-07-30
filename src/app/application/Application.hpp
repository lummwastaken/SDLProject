#pragma once

#include "RenderWindow.hpp"

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

		bool loadMedia();

		void runLoop();

	private:
		Application()
		{
		}

		void shutdown();
	};
}