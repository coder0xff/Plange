#ifndef AUTO_MAP_H
#define AUTO_MAP_H

#include <functional>
#include <mutex>

namespace parlex {
namespace details {

template<typename TKey, typename TValue>
class auto_map {
	std::function<TValue (TKey const &)> value_factory;
	std::map<TKey, TValue> storage;
	mutable std::mutex mutex;
public:
	auto_map(std::function<TValue (TKey const &)> valueFactory) : value_factory(valueFactory) {}

	auto_map() : value_factory([](TKey dontCare) { return TValue(); }) {}

	TValue const & operator()(TKey key) {
		std::unique_lock<std::mutex> lock(mutex);
		auto i = storage.find(key);
		if (i == storage.end()) {
			TValue result = value_factory(key);
			storage.insert(std::pair<TKey, TValue>(key, result));
			return result;
		}
		else {
			return *i;
		}
	}

	void Set(TKey key, TValue value) {
		std::unique_lock<std::mutex> lock(mutex);
		storage[key] = value;
	}

};

}
}

#endif
