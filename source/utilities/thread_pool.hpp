#ifndef THREAD_POOL_HPP
#define THREAD_POOL_HPP

#include <atomic>
#include <condition_variable>
#include <functional>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

#include "wait_flag.hpp"


class thread_pool {
public:
	static thread_pool & default_pool();

	explicit thread_pool(size_t threadCount = std::thread::hardware_concurrency());
	~thread_pool();

private:
	struct work_item {
		work_item(std::function<void(void *)> const & f, void * const data);

		std::function<void(void *)> const f;
		void * const data;
		wait_flag w;
	};

public:
	class work_handle {
		std::shared_ptr<work_item> item;
		explicit work_handle(std::shared_ptr<work_item> const & item) : item(item) {}
		friend class thread_pool;
	public:
		void wait() const {
			item->w();
		}
	};

	work_handle schedule(std::function<void(void *)> const & f, void * const userData = nullptr);

	std::vector<std::thread> threads;
	std::queue<std::shared_ptr<work_item>> queue;
	std::mutex m;
	std::condition_variable cv;
	std::atomic<size_t> handle_counter = 0;
	std::atomic<bool> destructing = false;

	void thread_loop();
};

#endif //THREAD_POOL_HPP