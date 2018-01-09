#ifndef THREAD_POOL_HPP
#define THREAD_POOL_HPP

#include <condition_variable>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>
#include <atomic>

class thread_pool {
public:
	explicit thread_pool(size_t threadCount = std::thread::hardware_concurrency());

	~thread_pool();

	void schedule(std::function<void (void *)> const & f, void * const userData) {
		std::unique_lock<std::mutex> l(m);
		queue.emplace(f, userData);
		cv.notify_one();
	}

private:
	struct work_item {
		work_item(std::function<void(void *)> const & f, void * const data);

		std::function<void(void *)> const f;
		void * const data;
		void operator()() const;
	};

	std::vector<std::thread> threads;
	std::queue<work_item> queue;
	std::mutex m;
	std::condition_variable cv;
	std::atomic<bool> destructing = false;

	void thread_loop();
};

#endif //THREAD_POOL_HPP