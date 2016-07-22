#include <functional>
#include <mutex>

class one_shot {
public:
	one_shot();
	void go(std::function<void ()> func);
private:
	bool state;
	std::mutex m;
};