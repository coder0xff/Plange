#include <condition_variable>
#include <deque>
#include <iostream>
#include <mutex>
#include <sstream>
#include <thread>

#include "parlex/details/subjob.hpp"
#include "parlex/details/logging.hpp"

#define IMMEDIATE_MODE

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
	  		cv.wait(lock, [this](){ return deque.size() > 0 || this->exit; }); //"this->" desired by MSVC
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

#ifndef IMMEDIATE_MODE
worker_t worker;
#endif // IMMEDIATE_MODE

template<>
void parlex::details::stringify(std::stringstream & ss) {}

//the thread safe entry point
void parlex::details::log_enque(std::string const * const item) {
#ifdef IMMEDIATE_MODE
	std::cout << *item;
	std::cout.flush();
	delete item;
#else
	std::unique_lock<std::mutex> lock(worker.mutex);
	worker.deque.emplace_back(item);
	worker.cv.notify_one();
#endif
}

