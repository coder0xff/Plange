#include "one_shot.hpp"

one_shot::one_shot() : state(false) { }

void one_shot::go(std::function<void()> const func)
{
	if (!state) {
		std::unique_lock<std::mutex> lock(m);
		if (!state) {
			func();
			state = true;
		}
	}
}
