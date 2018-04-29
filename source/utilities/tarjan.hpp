#ifndef TARJAN_HPP
#define TARJAN_HPP

//See https://en.wikipedia.org/wiki/Tarjan%27s_strongly_connected_components_algorithm

#include <functional>

std::vector<std::vector<size_t>> tarjan(size_t const vertexCount, std::function<std::vector<size_t> (size_t)> const & transitionFunctor, bool connectedComponentsOnly = false);

#endif //TARJAN_HPP
