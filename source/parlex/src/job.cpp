#include "logging.hpp"
#include "state_machine.hpp"
#include "job.hpp"
#include "terminal.hpp"
#include "context.hpp"
#include "parser.hpp"
#include "token.hpp"

namespace parlex {
namespace details {

job::job(parser & owner, std::u32string const & document, recognizer const & main) :
  document(document),
  main(main),
  owner(owner)
	{
		DBG("starting job using recognizer '", main, "'");

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
			state_machine const * machine = static_cast<state_machine const *>(&main);
			subjob * result = new subjob(*this, *machine, 0);
			producers.emplace(
				std::piecewise_construct,
				std::forward_as_tuple(matchClass),
				std::forward_as_tuple(result)
			);
			//seed the parser with the root state
			owner.work.emplace(std::make_tuple(result->construct_start_state_context(0), 0));
			owner.activeCount++;
			//give it a tickle!
			owner.work_cv.notify_one(); //parser::parse has mutex locked
		}
	}



void job::connect(match_class const & matchClass, context_ref const & c, int nextDfaState) {
	get_producer(matchClass).add_subscription(c, nextDfaState);
}

producer & job::get_producer(match_class const & matchClass) {
	std::unique_lock<std::mutex> lock(producers_mutex);
	if (producers.count(matchClass)) {
		return *producers[matchClass];
	} else {
		lock.unlock();
		if (matchClass.r.is_terminal()) {
			terminal const * t = static_cast<terminal const *>(&matchClass.r);
			token * result = new token(*this, *t, matchClass.document_position);
			lock.lock();
			producers.emplace(
				std::piecewise_construct,
				std::forward_as_tuple(matchClass),
				std::forward_as_tuple(result)
			);
		} else {
			state_machine const * machine = static_cast<state_machine const *>(&matchClass.r);
			subjob * result = new subjob(*this, *machine, matchClass.document_position);
			lock.lock();
			bool didEmplace = producers.emplace(
				std::piecewise_construct,
				std::forward_as_tuple(matchClass),
				std::forward_as_tuple(result)
			).second;
			lock.unlock();
			if (didEmplace) {
				result->start();
			}
		}
	}
	return *producers[matchClass];
}


}
}
