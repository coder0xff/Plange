#include "parlex/details/job.hpp"

#include "parlex/details/parser.hpp"
#include "parlex/details/state_machine_base.hpp"
#include "parlex/details/terminal.hpp"
#include "parlex/details/token.hpp"

#include "parlex/details/context.hpp"
#include "parlex/details/subjob.hpp"

#include "logging.hpp"

namespace parlex {
namespace details {

job::job(parser & owner, std::u32string const & document, grammar_base const & g, recognizer const & main, progress_handler_t progressHandler) :
	document(document),
	g(g),
	main(main),
	progress(0),
	owner(owner),
	progress_handler(progressHandler),
	progress_counter(0) {
	//DBG("starting job using recognizer '", main, "'");

	//similar to get_product, but different for constructor
	match_class matchClass(main, 0);
	if (main.is_terminal()) {
		terminal const * const t = static_cast<terminal const *>(&main);
		token * result = new token(*this, *t, 0);
		producers.emplace(
			std::piecewise_construct,
			std::forward_as_tuple(matchClass),
			std::forward_as_tuple(result)
		);
	} else {
		state_machine_base const * machine = static_cast<state_machine_base const *>(&main);
		subjob * result = new subjob(*this, *machine, 0);
		producers.emplace(
			std::piecewise_construct,
			std::forward_as_tuple(matchClass),
			std::forward_as_tuple(result)
		);
		//seed the parser with the root state
		result->increment_lifetime(); //reference code A
		owner.work.emplace(std::make_tuple(result->construct_start_state_context(0), 0));
		++owner.activeCount;
		//give it a tickle!
		owner.work_cv.notify_one(); //parser::parse has mutex locked
		result->finish_creation();
	}
}

void job::connect(match_class const & matchClass, context* const & c, int nextDfaState, behavior::leaf const * leaf) {
	get_producer(matchClass).add_subscription(c, nextDfaState, leaf);
}

producer& job::get_producer(match_class const & matchClass) {
	std::unique_lock<std::mutex> lock(producers_mutex);
	if (producers.count(matchClass)) {
		return *producers[matchClass];
	}
	lock.unlock();
	if (matchClass.r.is_terminal()) {
		terminal const * t = static_cast<terminal const *>(&matchClass.r);
		token * result = new token(*this, *t, matchClass.document_position);
		lock.lock();
		return *producers.emplace(
			std::piecewise_construct,
			std::forward_as_tuple(matchClass),
			std::forward_as_tuple(result)
		).first->second.get();
	}
	state_machine_base const * machine = static_cast<state_machine_base const *>(&matchClass.r);
	subjob * sj = new subjob(*this, *machine, matchClass.document_position);
	lock.lock();
	auto temp = producers.emplace(
		std::piecewise_construct,
		std::forward_as_tuple(matchClass),
		std::forward_as_tuple(sj)
	);
	subjob * result = static_cast<subjob*>(temp.first->second.get());
	lock.unlock();
	if (temp.second) {
		result->start();
	}
	return *result;
}


void job::update_progress(size_t completed)
{
	if (progress_handler) {
		size_t old_progress = progress.load();
		while (!progress_counter.compare_exchange_weak(old_progress, completed) && old_progress < completed);
		if (old_progress < completed) {
			progress_handler(completed, document.length());
		}
	}
}

}
}
