#ifndef INCLUDED_UTILITIES_WAIT_FLAG_HPP
#define INCLUDED_UTILITIES_WAIT_FLAG_HPP

#include <condition_variable>
#include <mutex>

class wait_flag
{
public:
	wait_flag() : state(false) {}
	wait_flag(const wait_flag& other) = delete;

    void operator()() {
        std::unique_lock<std::mutex> lock(sync);
        while (!state) {
            underlying.wait(lock);
        }
    }

    void set() {
        std::unique_lock<std::mutex> lock(sync);
        state = true;
        underlying.notify_all();
    }

private:
    std::condition_variable underlying;
    std::mutex sync;
    volatile bool state;
};

#endif // INCLUDED_UTILITIES_WAIT_FLAG_HPP
