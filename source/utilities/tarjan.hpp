#ifndef TARJAN_HPP
#define TARJAN_HPP

//See https://en.wikipedia.org/wiki/Tarjan%27s_strongly_connected_components_algorithm

#include <functional>
#include <optional>

template<typename TVertexIterator, typename TTransitionFunctor>
std::vector<std::vector<TVertexIterator>> tarjan(TVertexIterator const & begin, TVertexIterator const & end, TTransitionFunctor const & transitionFunctor, bool connectedComponentsOnly = false) {
	// if noSignularComponents == true, then the returned vector will not contain any std::vector<TVertexIterator> elements that have a size() == 1

	class vertex_info_t {
	public:
		vertex_info_t() : on_stack(false) {}
		std::optional<size_t> index;
		std::optional<size_t> lowlink;
		bool on_stack;
	};

	struct impl {
		TVertexIterator const & begin;
		TVertexIterator const & end;
		TTransitionFunctor const & transition_functor;
		bool const connected_components_only;

		size_t index;
		std::vector<TVertexIterator> s;
		std::vector<vertex_info_t> vertex_infos;
		std::vector<std::vector<TVertexIterator>> strongly_connected_components;
		//std::function<std::vector<TVertexIterator>(TVertexIterator const &)> const & transitionFunction
		impl(TVertexIterator const & begin, TVertexIterator const & end, TTransitionFunctor const & transitionFunctor, bool connectedComponentsOnly) : begin(begin), end(end), transition_functor(transitionFunctor), connected_components_only(connectedComponentsOnly), index(0) {
			size_t const vertexCount = end - begin;
			s.reserve(vertexCount);
			vertex_infos.resize(vertexCount);
			for (auto i = begin; i != end; ++i) {
				if (!vertex_infos[i - begin].index.has_value()) {
					strong_connect(i);
				}
			}
			if (!strongly_connected_components.empty() && strongly_connected_components.back().empty()) {
				strongly_connected_components.pop_back();
			}
		}

		void strong_connect(TVertexIterator const & v) {
			// Set the depth index for v to the smallest unused index
			int const vDelta = v - begin;
			vertex_info_t & vInfo = vertex_infos[vDelta];
			vInfo.lowlink = vInfo.index = index;
			++index;
			s.push_back(v);
			vInfo.on_stack = true;

			// Consider successors of v
			for (TVertexIterator wI : transition_functor(v)) {
				int const wDelta = wI - begin;
				vertex_info_t & wInfo = vertex_infos[wDelta];
				std::optional<size_t> & wIndex = wInfo.index;
				if (!wIndex.has_value()) {
					// Successor w has not yet been visited; recurse on it
					strong_connect(wI);
					vInfo.lowlink = std::min(vInfo.lowlink, wInfo.lowlink);
				} else if (wInfo.on_stack) {
					// Successor w is in stack S and hence in the current SCC
					// Note: The next line may look odd - but is correct.
					// It says w.index not w.lowlink; that is deliberate and from the original paper
					vInfo.lowlink = std::min(vInfo.lowlink, wInfo.index);
				}
			}

			// If v is a root node, pop the stack and generate an SCC
			if (vInfo.lowlink == vInfo.index) {
				if (strongly_connected_components.empty() || !strongly_connected_components.back().empty()) {
					if (connected_components_only && !strongly_connected_components.empty() && strongly_connected_components.back().size() < 2) {
						strongly_connected_components.pop_back();
					}
					strongly_connected_components.emplace_back();
				}
				int wDelta;
				do {
					TVertexIterator wI = s.back();
					s.pop_back();
					wDelta = wI - begin;
					vertex_info_t & wInfo = vertex_infos[wDelta];
					wInfo.on_stack = false;
					strongly_connected_components.back().push_back(wI);
				} while (wDelta != vDelta);
				if (strongly_connected_components.empty() || !strongly_connected_components.back().empty()) {
					if (connected_components_only && !strongly_connected_components.empty() && strongly_connected_components.back().size() < 2) {
						strongly_connected_components.pop_back();
					}
					strongly_connected_components.emplace_back();
				}
			}
		}

	};

	impl i(begin, end, transitionFunctor, connectedComponentsOnly);
	return std::move(i.strongly_connected_components);
}

#endif //TARJAN_HPP
