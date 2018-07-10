#ifndef INCLUDED_UTILITIES_TARJAN_HPP
#define INCLUDED_UTILITIES_TARJAN_HPP

#include <functional>
#include <vector>

//See https://en.wikipedia.org/wiki/Tarjan%27s_strongly_connected_components_algorithm

std::vector<std::vector<size_t>> tarjan(size_t const vertexCount, std::function<std::vector<size_t> (size_t)> const & transitionFunctor, bool connectedComponentsOnly = false);

#endif // INCLUDED_UTILITIES_TARJAN_HPP
