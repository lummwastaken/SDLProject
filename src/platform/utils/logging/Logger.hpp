#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

#define LOG_TRACE(...) SDLGame::Logger::getLogger()->trace(__VA_ARGS__)
#define LOG_DEBUG(...) SDLGame::Logger::getLogger()->debug(__VA_ARGS__)
#define LOG_INFO(...) SDLGame::Logger::getLogger()->info(__VA_ARGS__)
#define LOG_WARN(...) SDLGame::Logger::getLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...) SDLGame::Logger::getLogger()->error(__VA_ARGS__)
#define LOG_CRASH(...) SDLGame::Logger::getLogger()->critical(__VA_ARGS__)

namespace SDLGame
{
	class Logger
	{
	public:
		static void init();

		static void quit();

		inline static std::shared_ptr<spdlog::logger>& getLogger() { return platformLogger; }
	private:
		static std::shared_ptr<spdlog::logger> platformLogger;

		Logger() {};
	};
}