#include "parlex/detail/job.hpp"

#include "parlex/detail/parser.hpp"
#include "parlex/detail/state_machine_base.hpp"
#include "parlex/detail/terminal.hpp"
#include "parlex/detail/token.hpp"

#include "parlex/detail/context.hpp"
#include "parlex/detail/subjob.hpp"
#include "parlex/detail/grammar_base.hpp"

//#include "logging.hpp"

namespace parlex {
namespace detail {

job::job(parser & owner, std::u32string const & document, grammar_base const & g, size_t const rootRecognizerIndex, progress_handler_t const & progressHandler) :
	document(document),
	g(g),
	producers(new producer_table(document.size(), g.get_recognizer_count())),
	progress(0),
	owner(&owner),
	progress_handler(progressHandler),
	progress_counter(0) {
	//DBG("starting job using recognizer '", main, "'");

	//similar to get_product, but different for constructor
	//because parser::mutex is already locked
	match_class const matchClass(0, rootRecognizerIndex, 0);
	auto & storage = (*producers)(matchClass);
	auto const & root = g.get_recognizer(rootRecognizerIndex);
	if (root.is_terminal()) {
		auto const t = static_cast<terminal const *>(&root);
		storage.reset(new token(*this, 0, rootRecognizerIndex, *t));
	} else {
		auto const machine = static_cast<state_machine_base const *>(&root);
		auto result = new subjob(*this, 0, rootRecognizerIndex, *machine);
		storage.reset(result);
		//seed the parser with the root state
		result->begin_work_queue_reference(); //reference code A
		owner.work.emplace(&result->construct_start_state_context(0), 0);
		result->finish_creation();
		++owner.active_count;
		// start when parser::mutex is unlocked
		owner.work_cv.notify_one();
	}
}

void job::connect(match_class const & matchClass, context const & c, int const nextDfaState, leaf const * leaf) {
	get_producer(matchClass).add_subscription(c, nextDfaState, leaf);
}

producer& job::get_producer(match_class const & matchClass) {
	std::unique_lock<std::mutex> lock(producers_mutex);
	auto & storage = (*producers)(matchClass);
	if (storage) {
		return *storage;
	}
	auto const & r = g.get_recognizer(matchClass.recognizer_index);
	std::unique_ptr<producer> newUniquePtr;
	if (r.is_terminal()) {
		auto const t = static_cast<terminal const *>(&r);
		storage.reset(new token(*this, matchClass.document_position, matchClass.recognizer_index, *t));
		return *storage;
	} else {
		lock.unlock();
		auto const machine = static_cast<state_machine_base const *>(&r);
		auto sj = new subjob(*this, matchClass.document_position, matchClass.recognizer_index, *machine);
		lock.lock();
		if (!storage) { // is it still empty? (ie. dont kill an existing one!)
			storage.reset(sj);
			lock.unlock(); // may be used recursively by sj->start() so we need to unlock it again
			sj->start();
		}
		return *storage;
	}
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
