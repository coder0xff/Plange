#include "CollectionExp.hpp"
#include "value.hpp"

CollectionExp::CollectionExp()
{

}

CollectionExp::CollectionExp(CollectionExp const & other)
{
	for (auto const & element : other.elements) {
		elements.resize(elements.size() + 1);
		auto temp = clone(*element);
		elements.rbegin()->swap(temp);
	}
}


value CollectionExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
