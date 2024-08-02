#include "Timer.hpp"

namespace SDLGame
{
	void Timer::start()
	{
		mStarted = true;
		mPaused = false;

		mTicks = SDL_GetTicks64();
		mDiff = 0;
	}

	void Timer::stop()
	{
		mStarted = false;
		mPaused = false;
		mTicks = 0;
		mDiff = 0;
	}

	void Timer::pause()
	{
		if (mStarted && !mPaused)
		{
			mPaused = true;

			mDiff = SDL_GetTicks64() - mTicks;
			mTicks = 0;
		}
	}

	void Timer::unpause()
	{
		if (mStarted && mPaused)
		{
			mPaused = false;

			mTicks = SDL_GetTicks64() - mDiff;
			mDiff = 0;
		}
	}

	u64 Timer::getTicks()
	{
		u64 time = 0;

		if (mStarted)
		{
			if (mPaused)
			{
				time = mDiff;
			}
			else
			{
				time = SDL_GetTicks64() - mTicks;
			}
		}
		return time;
	}
}