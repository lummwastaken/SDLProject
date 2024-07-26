#include "Logger.hpp"

namespace SDLGame
{
	std::shared_ptr<spdlog::logger> Logger::platformLogger;

	void Logger::init()
	{
		try
		{
			spdlog::set_pattern("%^[%T] [%n] [%l]: %v%$");
			platformLogger = spdlog::basic_logger_mt("console", "logs/latest.log");
			platformLogger->set_level(spdlog::level::trace);
		}
		catch (const spdlog::spdlog_ex& ex)
		{
			printf("Could not initialize log! Log error: %s\n", ex.what());
		}
		LOG_TRACE("Successfully initialized Logger(s)");
	}

	void Logger::quit()
	{
		spdlog::shutdown();
	}
}