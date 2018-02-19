
#include <vector>
#include <functional>
#include <optional>
#include <algorithm>

std::vector<std::vector<size_t>> tarjan(size_t const vertexCount, std::function<std::vector<size_t>(size_t)> const & transitionFunctor, bool connectedComponentsOnly /*= false*/)
{
	// if connectedComponentsOnly == true, then the returned vector will not contain any std::vector<TVertexIterator> elements that have a size() == 1

	typedef std::function<std::vector<size_t>(size_t const &)> t_transition_functor;

	class vertex_info_t {
	public:
		vertex_info_t() : on_stack(false) {}
		std::optional<size_t> index;
		std::optional<size_t> lowlink;
		bool on_stack;
	};

	struct impl {
		size_t const vertex_count;
		t_transition_functor const & transition_functor;
		bool const connected_components_only;

		size_t index;
		std::vector<size_t> s;
		std::vector<vertex_info_t> vertex_infos;
		std::vector<std::vector<size_t>> strongly_connected_components;
		//std::function<std::vector<TVertexIterator>(TVertexIterator const &)> const & transitionFunction
		impl(size_t const vertexCount, t_transition_functor const & transitionFunctor, bool connectedComponentsOnly) : vertex_count(vertexCount), transition_functor(transitionFunctor), connected_components_only(connectedComponentsOnly), index(0) {
			s.reserve(vertexCount);
			vertex_infos.resize(vertexCount);
			for (size_t i = 0; i != vertexCount; ++i) {
				if (!vertex_infos[i].index.has_value()) {
					strong_connect(i);
				}
			}
			if (!strongly_connected_components.empty() && strongly_connected_components.back().empty()) {
				strongly_connected_components.pop_back();
			}
		}

		void strong_connect(size_t const & v) {
			// Set the depth index for v to the smallest unused index
			auto & vInfo = vertex_infos[v];
			vInfo.lowlink = vInfo.index = index;
			++index;
			s.push_back(v);
			vInfo.on_stack = true;

			// Consider successors of v
			for (size_t wI : transition_functor(v)) {
				vertex_info_t & wInfo = vertex_infos[wI];
				std::optional<size_t> & wIndex = wInfo.index;
				if (!wIndex.has_value()) {
					// Successor w has not yet been visited; recurse on it
					strong_connect(wI);
					vInfo.lowlink = std::min(vInfo.lowlink, wInfo.lowlink);
				}
				else if (wInfo.on_stack) {
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
				size_t w;
				do {
					w = s.back();
					s.pop_back();
					vertex_info_t & wInfo = vertex_infos[w];
					wInfo.on_stack = false;
					strongly_connected_components.back().push_back(w);
				} while (w != v);
				if (strongly_connected_components.empty() || !strongly_connected_components.back().empty()) {
					if (connected_components_only && !strongly_connected_components.empty() && strongly_connected_components.back().size() < 2) {
						strongly_connected_components.pop_back();
					}
					strongly_connected_components.emplace_back();
				}
			}
		}

	};

	impl i(vertexCount, transitionFunctor, connectedComponentsOnly);
	return std::move(i.strongly_connected_components);
}
