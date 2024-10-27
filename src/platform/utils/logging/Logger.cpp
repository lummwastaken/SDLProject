#include "Logger.hpp"

namespace SDLGame
{
	std::shared_ptr<spdlog::logger> Logger::platformLogger;

	void Logger::init(spdlog::level::level_enum level)
	{
		std::remove("../logs/latest.log");
		try
		{
			spdlog::set_pattern("%^[%T] [%n] [%l]: %v%$");
			platformLogger = spdlog::basic_logger_mt("console", "../logs/latest.log");
			platformLogger->set_level(level);
		}
		catch (const spdlog::spdlog_ex& ex)
		{
			printf("Could not initialize Logger(s)! Log error: %s\n", ex.what());
		}
		LOG_TRACE("Successfully initialized Logger(s)");
	}

	void Logger::quit()
	{
		LOG_TRACE("Shutting down Logger(s)");
		spdlog::shutdown();
	}
}