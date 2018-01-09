#include "thread_pool.hpp"

#include <cassert>

thread_pool::thread_pool(size_t threadCount) {
	assert(threadCount > 0);
	threads.reserve(threadCount);
	for (size_t i = 0; i < threadCount; ++i) {
		threads.emplace_back([=]() { thread_loop(); });
	}
}

thread_pool::~thread_pool() {
	destructing = true;
	cv.notify_all();
	for (auto & t : threads) {
		t.join();
	}
}

thread_pool::work_item::work_item(std::function<void(void *)> const & f, void * const data): f(f), data(data) {}

void thread_pool::work_item::operator()() const {
	f(data);
}

void thread_pool::thread_loop() {
	std::unique_lock<std::mutex> l(m);
	while (!destructing || queue.size() > 1) {
		if (!queue.empty()) {
			auto const workItem = queue.front();
			queue.pop();
			l.unlock();
			workItem();
			l.lock();
		} else {
			cv.wait(l);
		}
	}
}
