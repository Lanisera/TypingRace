#include "timer/timer.h"
#include <functional>

void Timer::restart()
{
	shotted = false;
	pass_time = 0;
}

void Timer::set_wait_time(double time)
{
	wait_time = time;
}

void Timer::set_one_shot(bool flag)
{
	one_shot = false;
}

void Timer::set_on_timeout(std::function<void()> on_finished)
{
	on_timeout = on_finished;
}

void Timer::pasue()
{
	pasued = true;
}

void Timer::resume()
{
	pasued = false;
}

void Timer::on_update(double delta)
{
	if (pasued) return ;

	pass_time += delta;
	if (pass_time >= wait_time)
	{
		bool can_shot = !one_shot || (one_shot && !shotted);
		shotted = true;
		if (can_shot && on_timeout)
			on_timeout();
		pass_time -= wait_time;
	}
}
