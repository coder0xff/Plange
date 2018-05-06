#include "parlex/detail/abstract_syntax_semilattice.hpp"

#include <queue>

#include "utils.hpp"

#include "parlex/detail/grammar.hpp"

namespace parlex {
namespace detail {

abstract_syntax_semilattice::abstract_syntax_semilattice(match const root) : root(root) { }

bool abstract_syntax_semilattice::is_rooted() const {
	auto const i = derivations_of_matches.find(root);
	return i != derivations_of_matches.end() && !i->second.empty();
}

void abstract_syntax_semilattice::cut(std::set<match> const & matches) {
	std::map<match, std::set<match>> reversedDependencies;
	for (auto const & matchAndDerivations : derivations_of_matches) {
		for (auto const & derivation : matchAndDerivations.second) {
			for (auto const & m : derivation) {
				reversedDependencies[m].insert(matchAndDerivations.first);
			}
		}
	}
	std::queue<match> pending;
	for (auto const & m : matches) {
		pending.push(m);
	}
	while (!pending.empty()) {
		auto const m = pending.front();
		pending.pop();
		if (derivations_of_matches.erase(m) == 1) {
			for (auto const & n : reversedDependencies[m]) {
				std::set<derivation> newDerivations;
				for (auto const & p : derivations_of_matches[n]) {
					auto cutDerivation = false;
					for (auto const & o : p) {
						if (!(o < m) && !(m < o)) {
							cutDerivation = true;
							break;
						}
					}
					if (!cutDerivation) {
						newDerivations.insert(p);
					}
				}
				if (newDerivations.empty()) {
					pending.push(n);
				}
				else {
					derivations_of_matches[n].swap(newDerivations);
				}
			}
		}
	}
}

void abstract_syntax_semilattice::prune_detached() {
	std::set<match> unconnecteds;
	for (auto const & entry : derivations_of_matches) {
		unconnecteds.insert(entry.first);
	}
	std::queue<match> pending;
	unconnecteds.erase(root);
	pending.push(root);
	while (!pending.empty()) {
		auto const m = pending.front();
		pending.pop();
		for (auto const & derivation : derivations_of_matches[m]) {
			for (auto const & child : derivation) {
				if (unconnecteds.erase(child) > 0) {
					pending.push(child);
				}
			}
		}
	}
	for (auto const & unconnected : unconnecteds) {
		derivations_of_matches.erase(unconnected);
	}
}

std::string abstract_syntax_semilattice::to_dot(grammar const & g) const {
	std::string result = "digraph {\n";
	std::set<match> completed;
	for (auto const & entry : derivations_of_matches) {
		auto const i = entry.first;
		completed.insert(i);
		auto const & iRecognizer = g.get_recognizer(i.recognizer_index);
		auto const fromName = iRecognizer.name + ":" + std::to_string(i.document_position + 1) + ":" + std::to_string(i.consumed_character_count);
		for (auto const & j : entry.second) {
			for (match const & k : j) {
				auto const & kRecognizer = g.get_recognizer(k.recognizer_index);
				auto const toName = kRecognizer.name + ":" + std::to_string(k.document_position + 1) + ":" + std::to_string(k.consumed_character_count);
				result += "\t" + enquote(fromName) + " -> " + enquote(toName) + "\n";
			}
		}
	}
	result += "}";
	return result;
}

//std::string abstract_syntax_semilattice::to_concrete_dot(std::u32string const & document) {
//	std::string result = "digraph {\n";
//	std::set<match> completed;
//	for (auto const & entry : derivations_of_matches) {
//		auto const i = entry.first;
//		completed.insert(i);
//		auto const fromName = i.r.name + ":" + std::to_string(i.document_position + 1) + ":" + std::to_string(i.consumed_character_count) + "\n" + to_utf8(document.substr(i.document_position, i.consumed_character_count));
//		for (auto const & j : entry.second) {
//			for (match const & k : j) {
//				auto const toName = k.r.name + ":" + std::to_string(k.document_position + 1) + ":" + std::to_string(k.consumed_character_count) + "\n" + to_utf8(document.substr(k.document_position, k.consumed_character_count));
//				result += "\t" + enquote(fromName) + " -> " + enquote(toName) + "\n";
//			}
//		}
//	}
//	result += "}";
//	return result;
//}

uint64_t abstract_syntax_semilattice::variation_count() const {
	uint64_t result = 1;
	for (auto const & derivation : derivations_of_matches) {
		result *= derivation.second.size();
	}
	return result;
}


std::set<derivation> const & abstract_syntax_semilattice::lookup(match const & m) const
{
	auto const i = derivations_of_matches.find(m);
	if (i == derivations_of_matches.end()) {
		throw std::runtime_error("derivations not found");
	}
	return i->second;
}

std::vector<ast_node> abstract_syntax_semilattice::build_tree(match const & m) const {
	std::vector<ast_node> results;
	auto const i = derivations_of_matches.find(m);
	throw_assert(i != derivations_of_matches.end());
	auto const & ps = i->second;
	if (!ps.empty()) {
		auto const & p = *ps.begin();
		for (auto const & t : p) {
			results.emplace_back(t, build_tree(t), t.l);
		}
	}
	return results;
}

abstract_syntax_tree abstract_syntax_semilattice::tree() const {
	if (!is_rooted()) {
		throw std::runtime_error("The document could not be parsed.");
	}
	if (variation_count() > 1) {
		throw std::runtime_error("The document is ambiguous.");
	}
	return ast_node(root, build_tree(root), nullptr);
}

} // namespace detail
} // namespace parlex
