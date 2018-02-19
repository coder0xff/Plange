#ifndef ONE_SHOT_HPP
#define ONE_SHOT_HPP

#include <functional>
#include <mutex>

class one_shot {
public:
	one_shot();
	void go(std::function<void ()> const & func);
private:
	bool state;
	std::mutex m;
};

#endif