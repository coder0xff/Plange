#include "document_representation.hpp"

namespace parlex {

std::shared_ptr<production_node> get_or_add_production(std::map<std::string, std::shared_ptr<production_node>> & productionNodes, std::string name) {
	auto i = productionNodes.find(name);
	if (i == productionNodes.end()) {
		return productionNodes[name] = new production_node{ name = name };
	} else {
		return i->second;
	}
}

std::map<std::string, std::shared_ptr<production_node>> make(std::shared_ptr<details::behavior_node> root) {
	auto const& as_repetition = std::dynamic_pointer_cast<details::repetition>(root);
	if (as_repetition != nullptr) {
		
	}
}

}
