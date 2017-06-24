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

	TValue & operator()(TKey key) {
		std::unique_lock<std::mutex> lock(mutex);
		// only run value_factory if not found, i.e. no emplace_back
		auto i = storage.find(key);
		if (i == storage.end()) {
			TValue value = value_factory(key); 
			i = storage.insert(std::pair<TKey, TValue>(key, value)).first;
		}
		return i->second;
	}

	void Set(TKey key, TValue value) {
		std::unique_lock<std::mutex> lock(mutex);
		storage[key] = value;
	}

};

#endif //AUTO_MAP_C_HPP