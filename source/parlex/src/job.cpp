#include "parlex/detail/job.hpp"

#include "parlex/detail/parser.hpp"
#include "parlex/detail/state_machine_base.hpp"
#include "parlex/detail/terminal.hpp"
#include "parlex/detail/token.hpp"

#include "parlex/detail/context.hpp"
#include "parlex/detail/subjob.hpp"

#include "logging.hpp"

namespace parlex {
namespace detail {

job::job(parser & owner, std::u32string const & document, grammar_base const & g, recognizer const & main, progress_handler_t const progressHandler) :
	document(document),
	g(g),
	main(main),
	progress(0),
	owner(owner),
	progress_handler(progressHandler),
	progress_counter(0) {
	//DBG("starting job using recognizer '", main, "'");

	//similar to get_product, but different for constructor
	//because parser::mutex is already locked
	match_class matchClass(main, 0);
	if (main.is_terminal()) {
		auto const t = static_cast<terminal const *>(&main);
		auto result = new token(*this, *t, 0);
		producers.emplace(
			std::piecewise_construct,
			std::forward_as_tuple(matchClass),
			std::forward_as_tuple(result)
		);
	} else {
		auto const machine = static_cast<state_machine_base const *>(&main);
		auto result = new subjob(*this, *machine, 0);
		producers.emplace(
			std::piecewise_construct,
			std::forward_as_tuple(matchClass),
			std::forward_as_tuple(result)
		);
		//seed the parser with the root state
		result->begin_work_queue_reference(); //reference code A
		owner.work.emplace(&result->construct_start_state_context(0), 0);
		result->finish_creation();
		++owner.active_count;
		// start when parser::mutex is unlocked
		owner.work_cv.notify_one();
	}
}

void job::connect(match_class const & matchClass, context const & c, int const nextDfaState, behavior::leaf const * leaf) {
	get_producer(matchClass).add_subscription(c, nextDfaState, leaf);
}

producer& job::get_producer(match_class const & matchClass) {
	std::unique_lock<std::mutex> lock(producers_mutex);
	if (producers.count(matchClass)) {
		return *producers[matchClass];
	}
	lock.unlock();
	if (matchClass.r.is_terminal()) {
		auto const t = static_cast<terminal const *>(&matchClass.r);
		auto result = new token(*this, *t, matchClass.document_position);
		lock.lock();
		return *producers.emplace(
			std::piecewise_construct,
			std::forward_as_tuple(matchClass),
			std::forward_as_tuple(result)
		).first->second.get();
	}
	auto const machine = static_cast<state_machine_base const *>(&matchClass.r);
	auto sj = new subjob(*this, *machine, matchClass.document_position);
	lock.lock();
	auto const temp = producers.emplace(
		std::piecewise_construct,
		std::forward_as_tuple(matchClass),
		std::forward_as_tuple(sj)
	);
	auto result = static_cast<subjob*>(temp.first->second.get());
	lock.unlock();
	if (temp.second) {
		result->start();
	}
	return *result;
}


void job::update_progress(size_t const completed)
{
	if (progress_handler) {
		size_t oldProgress = progress.load();
		while (!progress_counter.compare_exchange_weak(oldProgress, completed) && oldProgress < completed) {}
		if (oldProgress < completed) {
			progress_handler(completed, document.length());
		}
	}
}

}
}
