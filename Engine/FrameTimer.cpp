#include "FrameTimer.h"
using namespace std::chrono;

FrameTimer::FrameTimer()
{
	auto last = steady_clock::now();
}

float FrameTimer::Mark()
{
	const auto old = last;
	last = steady_clock::now();
	const duration<float> frameTime = last - old;
	return frameTime.count();
}
