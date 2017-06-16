#ifndef AUTO_MAP_C_HPP
#define AUTO_MAP_C_HPP

#include <functional>
#include <map>
#include <mutex>

template <typename TKey, typename TValue>
class auto_map_c {
	std::function<TValue (TKey const &)> value_factory;
	std::map<TKey, TValue> storage;
	mutable std::mutex mutex;
public:
	auto_map_c(std::function<TValue (TKey const &)> valueFactory) : value_factory(valueFactory) {
	}

	auto_map_c() : value_factory([](TKey) { return TValue(); }) {
	}

	TValue const& operator()(TKey key) {
		std::unique_lock<std::mutex> lock(mutex);
		// only run value_factory if not found, i.e. no emplace_back
		auto i = storage.find(key);
		if (i == storage.end()) {
			TValue result = value_factory(key); 
			storage.insert(std::pair<TKey, TValue>(key, result));
			return result;
		}
		return *i;
	}

	void Set(TKey key, TValue value) {
		std::unique_lock<std::mutex> lock(mutex);
		storage[key] = value;
	}

};

#endif //AUTO_MAP_C_HPP
