#pragma once

#include <SDL_timer.h>

namespace SDLGame
{
	class Timer
	{
	public:
		Timer() :
			mTicks(0),
			mDiff(0),
			mPaused(false),
			mStarted(false)
		{
		}

		void start();
		void stop();
		void pause();
		void unpause();

		u64 getTicks();

		bool isStarted() { return mStarted; }
		bool isPaused() { return mPaused && mStarted; }
	private:
		u64 mTicks;
		u64 mDiff;

		bool mPaused;
		bool mStarted;
	};
}