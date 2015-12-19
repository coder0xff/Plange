#include "logging.hpp"

#include <condition_variable>
#include <deque>
#include <iostream>
#include <mutex>
#include <sstream>
#include <thread>

struct worker_t {
	std::mutex mutex;
	std::deque<std::string const *> deque;
	std::condition_variable cv;

	worker_t() : 
	  exit(false),
	  thread([&]() {
	  	std::unique_lock<std::mutex> lock(mutex);
	  	while (!exit) {
	  		while (deque.size() > 0) {
	  			std::string const * const item = deque.front();
	  			deque.pop_front();
	  			lock.unlock();
	  			std::cout << *item;
	  			delete item;
	  			lock.lock();
	  		}
	  		cv.wait(lock, [this](){ return deque.size() > 0 || exit; });
	  	}		
	  })
	{ 
		DBG("Debug logging is enabled");
	}

	~worker_t() {
		exit = true;
		cv.notify_one();
		thread.join();
	}

private:
	bool exit;
	std::thread thread;
};

worker_t worker;

template<>
void parlex::details::stringify(std::stringstream & ss) {}

//the thread safe entry point
void parlex::details::log_enque(std::string const * const item) {
	std::unique_lock<std::mutex> lock(worker.mutex);
	worker.deque.emplace_back(item);
	worker.cv.notify_one();
}

