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

thread_pool::work_handle thread_pool::schedule(std::function<void(void *)> const & f, void * const userData) {
	std::unique_lock<std::mutex> l(m);
	work_handle result(queue.emplace(new work_item(f, userData)));
	cv.notify_one();
	return result;
}

thread_pool & thread_pool::default_pool() {
	static thread_pool result;
	return result;
}

thread_pool::work_item::work_item(std::function<void(void *)> const & f, void * const data): f(f), data(data) {}

void thread_pool::thread_loop() {
	std::unique_lock<std::mutex> l(m);
	while (!destructing || queue.size() > 1) {
		if (!queue.empty()) {
			auto workItem = queue.front();
			queue.pop();
			l.unlock();
			workItem->f(workItem->data);
			workItem->w.set();
			l.lock();
		} else {
			cv.wait(l);
		}
	}
}
