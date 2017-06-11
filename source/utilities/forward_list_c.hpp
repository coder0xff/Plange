#ifndef FORWARD_LIST_C_HPP
#define FORWARD_LIST_C_HPP

#include <atomic>
#include <memory>
#include <vector>

#include "utils.hpp"
#include <list>

namespace details {
namespace forward_list_c_details {

// provides a globally unique pointer used for the terminal node
constexpr struct {
} dead_v;
constexpr void * dead = (void*)&dead_v;

// provides a globally unique pointer for the lock node
constexpr struct {
} spin_v;
constexpr void * spin = (void*)&spin_v;

constexpr std::memory_order combine_memory_order(std::memory_order loadOrder, std::memory_order storeOrder);

}
}

//similar to std::forward_list, but thread safe and partiallt lock free
template <class T>
class forward_list_c {

	template <class U>
	class ForwardIterator;

	class node;

	static constexpr node * terminal = (node*)details::forward_list_c_details::dead;
	static constexpr node * spin = (node*)details::forward_list_c_details::spin;

	class node {
	public:
		friend class ForwardIterator<T>;
		T value;
		std::atomic<node*> next;
		std::atomic<int> referenceCount; //for keeping a node referenced by an iterator alive

		node(T const & value) : value(value), next(terminal), referenceCount(1) {
		}

		node(T && value) : value(std::move(value)), next(terminal), referenceCount(1) {
		}

		template <class... U>
		node(U ... params) : value(std::forward(params)...), next(terminal), referenceCount(1) {
		}

		~node() {			
			node * n = owner_lock(next, std::memory_order_seq_cst); //change next to spin
			decrement_reference_count(n, std::memory_order_seq_cst, std::memory_order_seq_cst); //release ownership of next
			next.store(terminal);
		}
	};

	//lock free, increment node::referenceCount, used for iterator and for prior-node's link
	static void decrement_reference_count(node *& n, std::memory_order loadOrder, std::memory_order storeOrder) {
		throw_assert(n != nullptr);
		throw_assert(n != terminal); //not a valid node
		throw_assert(n != spin); //not a valid node
		if (n && n->referenceCount.fetch_sub(1, details::forward_list_c_details::combine_memory_order(loadOrder, storeOrder)) == 1) {
			delete n;
		}
		n = nullptr;
	}

	//lock free, decrement node::referenceCount, used for iterator and for for prior-node's link
	//return a new "ownership"
	static node* increment_reference_count(node * n, std::memory_order loadOrder, std::memory_order storeOrder) {
		throw_assert(n != nullptr);
		throw_assert(n != terminal);
		throw_assert(n != spin);
		n->referenceCount.fetch_add(1, details::forward_list_c_details::combine_memory_order(loadOrder, storeOrder));
		return n;
	}

	//lock free, swap the node *s in left and right, 
	static void exchange(std::atomic<node*> & left, node * & right, std::memory_order loadOrder, std::memory_order storeOrder) {
		throw_assert(right != nullptr);
		throw_assert(right != terminal); // may not be terminal, because it's owned by the right
		throw_assert(right != spin); //invalid node
		node * n = left.load(loadOrder);
		do {
			while (n == spin) {
				n = left.load(loadOrder);
			}
		} while (!left.compare_exchange_weak(n, right, storeOrder, loadOrder));
		throw_assert(n != nullptr);
		throw_assert(n != terminal); // may not be terminal, because it's it was owned by left
		right = n;
	}

	//NOT lock free on left, lock free on right
	static void exchange(std::atomic<node*> & left, std::atomic<node*> & right, std::memory_order loadOrder, std::memory_order storeOrder) {
		node * temp = owner_lock(left, loadOrder);
		exchange(right, temp, loadOrder, storeOrder);
		owner_unlock(left, temp, storeOrder);
	}

	//NOT lock free, set atomic_ptr to spin and return the node * leaving the node locked, unless atomic_ptr is already terminal then return terminal
	//"ownership" is transferred from atomic_ptr to the return value
	static node* owner_lock(std::atomic<node*> & atomic_ptr, std::memory_order loadOrder) {
		node * n = atomic_ptr.load(loadOrder);
		do {
			while (n == spin) { //wait for owner_unlock
				n = atomic_ptr.load(loadOrder);
			}
		} while (!atomic_ptr.compare_exchange_weak(n, spin, std::memory_order_release)); // weak and no acquire because lock can occur at systems leisure, release because observers must see spin immediately
		// n has been updated to final value (per loadOrder) before atomic_ptr was set to spin
		if (n == terminal) { // the node has been deleted already
			// put terminal back in to owner_unlock
			atomic_ptr.store(terminal, std::memory_order_relaxed); // relaxed because observer will see spin if not terminal
			return terminal;
		} // else stays locked
		return n;
	}

	//lock free, but requires a preceding call to lock, changes atomic_ptr from spin to n, sets n to nullptr
	//"ownership" is transfered from n to atomic_ptr
	static void owner_unlock(std::atomic<node*> & atomic_ptr, node * & n, std::memory_order storeOrder) {
		throw_assert(n != nullptr);
		throw_assert(n != spin);
		throw_assert(atomic_ptr.load(std::memory_order_relaxed) == spin); // relaxed because it was set to spin by the current thread
		atomic_ptr.store(n, storeOrder);
		n = nullptr; // make sure the caller cant use the pointer anymore
	}

	//NOT lock free, 
	static node* new_ownership(std::atomic<node*> & atomic_ptr, std::memory_order loadOrder, std::memory_order storeOrder) {
		node * temp = owner_lock(atomic_ptr, loadOrder);
		if (temp == terminal) { 
			return terminal;
		}
		node * result = temp ? increment_reference_count(temp, loadOrder, storeOrder) : terminal;
		owner_unlock(atomic_ptr, temp, storeOrder);
		return result;
	}

	template <class U>
	//construction is lock free (though begin() is not)
	//incrementing is NOT lock free
	class ForwardIterator {
		friend class forward_list_c;
		node * current;
	public:
		typedef std::forward_iterator_tag iterator_category;
		typedef U value_type;
		typedef U & reference;
		typedef U * pointer;

		ForwardIterator() : current(terminal) {
		}

		ForwardIterator(node * n) : current(n ? increment_reference_count(n, std::memory_order_seq_cst, std::memory_order_seq_cst) : terminal) {
		}

		ForwardIterator(ForwardIterator const & other) : current(other.current != terminal ? increment_reference_count(other.current, std::memory_order_seq_cst, std::memory_order_seq_cst) : terminal) {
		}

		ForwardIterator(ForwardIterator && other) noexcept : current(terminal) { std::swap(current, other.current); }

		~ForwardIterator() {
			decrement_reference_count(current, std::memory_order_seq_cst, std::memory_order_seq_cst);
		}

		ForwardIterator& operator=(ForwardIterator const & other) {
			if (current != terminal) {
				decrement_reference_count(current, std::memory_order_seq_cst, std::memory_order_seq_cst);
			}
			current = other.current ? increment_reference_count(other.current, std::memory_order_seq_cst, std::memory_order_seq_cst) : terminal;
			return *this;
		}

		T& operator*() { return current->value; }
		T& operator->() { return current->value; }

		ForwardIterator operator++() {
			throw_assert(current != terminal); // this is the end()
			node * temp = new_ownership(current->next, std::memory_order_seq_cst, std::memory_order_seq_cst);
			std::swap(current, temp);
			if (temp != terminal) {
				decrement_reference_count(temp, std::memory_order_seq_cst, std::memory_order_seq_cst);
			}
			return *this;
		}

		ForwardIterator operator++(int) {
			throw_assert(current != terminal); //this is the end()
			ForwardIterator temp = *this;
			++*this;
			return temp;
		}

		friend void swap(ForwardIterator & a, ForwardIterator & b) noexcept {
			using std::swap; // bring in swap for built-in types
			std::swap(a.current, b.current);
		}

		operator ForwardIterator<const T>() const {
			return ForwardIterator<const T>(current);
		}

		bool operator==(ForwardIterator const & rhs) {
			return current == rhs.current;
		}

		bool operator!=(ForwardIterator const & rhs) {
			return !(*this == rhs);
		}
	};

public:
	typedef T value_type;
	typedef value_type & reference;
	typedef const value_type & const_reference;
	typedef value_type * pointer;
	typedef value_type const * const_pointer;
	typedef ForwardIterator<T> iterator;
	typedef ForwardIterator<const T> const_iterator;

	forward_list_c() : first(terminal) {
	}

	forward_list_c(forward_list_c const & copy) {
		std::atomic<node *> * nextPtr = &first;
		for (auto const & v : copy) {
			std::atomic<node *> & next = *nextPtr;
			node * newNode = new node(v);
			next.store(newNode);
			nextPtr = &newNode->next;
		}
	}

	forward_list_c(forward_list_c&& move) noexcept : first(terminal) {
		exchange(move.first, first, std::memory_order_seq_cst, std::memory_order_seq_cst);
	}

	~forward_list_c() {
		clear();
	}

	//lock free
	bool empty(std::memory_order loadOrder = std::memory_order_seq_cst) {
		return first.load(loadOrder) == terminal;
	}

	//lock free
	//iterators will still contain correct values,
	//but incrementing them or inserting after them will result in a default constructed iterator
	int clear(std::memory_order loadOrder = std::memory_order_seq_cst, std::memory_order storeOrder = std::memory_order_seq_cst) {
		node * oldFirst = terminal;
		exchange(first, oldFirst, loadOrder, storeOrder);
		//if we just delete the first node, it may cascade down all the
		//subsequent nodes. This would be fine, if not for the possibility
		//of blowing the stack. Instead we delete them in reverse.
		std::vector<node*> nodes;
		while (oldFirst) {
			nodes.push_back(oldFirst);
			node * temp = terminal;
			exchange(oldFirst->next, temp, loadOrder, storeOrder);
			oldFirst = temp;
		}
		for (auto i = nodes.rbegin(); i != nodes.rend(); ++i) {
			decrement_reference_count(*i, loadOrder, storeOrder);
		}
		return nodes.size();
	}

	//PARTIALLY lock free
	//insert will not block
	//iterators will block, and then reach end()
	//elements inserted during this algorithm will be removed as well
	//use locked_clear to have inserts fail instead
	int locked_clear(std::memory_order loadOrder = std::memory_order_seq_cst, std::memory_order storeOrder = std::memory_order_seq_cst) {
		std::list<node*> nodes;
		{
			node * i = terminal;
			exchange(first, i, loadOrder, storeOrder);
			//if we just delete the first node, it may cascade down all the
			//subsequent nodes. This would be fine, if not for the possibility
			//of blowing the stack. Instead we delete them in reverse.
			while (i) {
				nodes.push_back(i);
				node * temp = spin;
				exchange(i->next, temp, loadOrder, storeOrder); //lock all the nodes
				i = temp;
			}
		}
		for (auto const & i = nodes.rbegin(); i != nodes.rend(); ++i) {
			decrement_reference_count(*i, loadOrder, storeOrder); // remove prior nodes reference
			i->next.store(terminal, storeOrder); // unlink
		}
		return nodes.size(); // return number of delete elements
	}

	//NOT lock free
	T& front(std::memory_order loadOrder = std::memory_order_seq_cst) {
		return *begin(loadOrder);
	}

	//lock free
	void push_front(const T & value, std::memory_order loadOrder = std::memory_order_seq_cst, std::memory_order storeOrder = std::memory_order_seq_cst) {
		insert_node(first, new node(value), loadOrder, storeOrder);
	}

	//lock free
	void push_front(T && value, std::memory_order loadOrder = std::memory_order_seq_cst, std::memory_order storeOrder = std::memory_order_seq_cst) {
		auto result = insert_node(first, new node(std::move(value)), loadOrder, storeOrder);
		throw_assert(result.current != terminal);
	}

	//lock free
	template <class... U>
	void emplace_front(U ... params) {
		insert_node(first, new node(params...), std::memory_order_seq_cst, std::memory_order_seq_cst);
	}

	//lock free
	template <class... U>
	void emplace_front_ordered(std::memory_order loadOrder, std::memory_order storeOrder, U ... params) {
		insert_node(first, new node(params...), loadOrder, storeOrder);
	}

	//NOT lock free
	bool pop_front(T * value, std::memory_order loadOrder = std::memory_order_seq_cst, std::memory_order storeOrder = std::memory_order_seq_cst) {
		return remove_node(first, &value, loadOrder, storeOrder);
	}

	//NOT lock free
	iterator begin(std::memory_order loadOrder = std::memory_order_seq_cst, std::memory_order storeOrder = std::memory_order_seq_cst) {
		node * n = new_ownership(first, loadOrder, storeOrder);
		iterator result(n);
		decrement_reference_count(n, loadOrder, storeOrder);
		return result;
	}

	//lock free
	iterator end() {
		return iterator();
	}

	//NOT lock free
	const_iterator begin(std::memory_order loadOrder = std::memory_order_seq_cst, std::memory_order storeOrder = std::memory_order_seq_cst) const {
		node * n = new_ownership(first, loadOrder, storeOrder);
		const_iterator result(n);
		decrement_reference_count(n, loadOrder, storeOrder);
		return result;
	}

	//lock free
	const_iterator end() const {
		return const_iterator();
	}

	//lock free - except construction of iterator
	//returns a default constructed iterator if position is no longer valid
	iterator insert_after(const_iterator position, T const & value, std::memory_order loadOrder = std::memory_order_seq_cst, std::memory_order storeOrder = std::memory_order_seq_cst) {
		return insert_node(position.current->next, new node(value), loadOrder, storeOrder);
	}

	//lock free - except construction of iterator
	iterator insert_after(const_iterator position, T && value, std::memory_order loadOrder = std::memory_order_seq_cst, std::memory_order storeOrder = std::memory_order_seq_cst) {
		return insert_node(position.current->next, new node(value), loadOrder, storeOrder);
	}

	//lock free
	iterator insert_after(const_iterator pos, int count, const T & value, std::memory_order loadOrder = std::memory_order_seq_cst, std::memory_order storeOrder = std::memory_order_seq_cst) {
		if (count <= 0) return iterator();
		iterator result = pos = insert_after(pos, value, loadOrder, storeOrder);
		for (int i = 1; i < count; i++) {
			pos = insert_after(pos, value, loadOrder, storeOrder);
		}
		return result;
	}

	//lock free
	template <class InputIt>
	iterator insert_after(const_iterator pos, InputIt first, InputIt last, std::memory_order loadOrder = std::memory_order_seq_cst, std::memory_order storeOrder = std::memory_order_seq_cst) {
		if (first == last) return iterator();
		iterator result = pos = insert_after(pos, *first, loadOrder, storeOrder);
		++first;
		while (first != last) {
			pos = insert_after(pos, first, loadOrder, storeOrder);
			++first;
		}
		return result;
	}

	//lock free
	iterator insert_after(const_iterator pos, std::initializer_list<T> ilist, std::memory_order loadOrder = std::memory_order_seq_cst, std::memory_order storeOrder = std::memory_order_seq_cst) {
		return insert_after(pos, ilist.begin(), ilist.end(), loadOrder, storeOrder);
	}

	//lock free
	template <class... U>
	iterator emplace_after(const_iterator position, U &&... params) {
		return insert_node(position, new node(std::forward(params)...));
	}

	//lock free
	template <class... U>
	iterator emplace_after_ordered(const_iterator position, std::memory_order loadOrder, std::memory_order storeOrder, U &&... params) {
		return insert_node(position, new node(std::forward(params)...), loadOrder, storeOrder);
	}

	//lock free
	//all the elements after position are moved to a new forward_list_c
	bool separate_after(const_iterator position, forward_list_c<T> *& result, std::memory_order loadOrder = std::memory_order_seq_cst, std::memory_order storeOrder = std::memory_order_seq_cst) {
		node * n = seperate(position.current->next, loadOrder, storeOrder);
		if (!n) return false;
		result = new forward_list_c<T>();
		result->first = n;
		return true;
	}

	void concat(forward_list_c & other, std::memory_order loadOrder = std::memory_order_seq_cst, std::memory_order storeOrder = std::memory_order_seq_cst) {
		node * n = seperate(other.first, loadOrder, storeOrder);
		concat(n);
	}

	//NOT lock free
	bool erase_after(const_iterator position, T & value, std::memory_order loadOrder = std::memory_order_seq_cst, std::memory_order storeOrder = std::memory_order_seq_cst) {
		return remove_node(position.current->next, value, loadOrder, storeOrder);
	}

	//NOT lock free on a, lock free on b
	friend void swap(forward_list_c & a, forward_list_c & b) noexcept {
		exchange(a.first, b.first);
	}

private:
	mutable std::atomic<node*> first; //mutable because iterator construction requires a lock

	static iterator insert_node(std::atomic<node*> & atomic_ptr, node * n, std::memory_order loadOrder, std::memory_order storeOrder) {
		iterator result(n); //it's possible that the node is removed before we return, so do this early
		n->next.store(n, storeOrder);
		exchange(n->next, atomic_ptr, loadOrder, storeOrder);
		return result;
	}

	// lock-free, removes all the nodes from *atomic_ptr forward, and returns that node with links still intact
	static node* seperate(std::atomic<node*> & atomic_ptr, std::memory_order loadOrder, std::memory_order storeOrder) {
		node * oldNext = terminal;
		exchange(atomic_ptr, oldNext, loadOrder, storeOrder);
		return oldNext;
	}

	static void concat(std::atomic<node*> & first, node * n, std::memory_order loadOrder, std::memory_order storeOrder) {
		if (n == terminal) return;
		std::atomic<node*> * atomic_ptr_ptr = &first;
		node * temp = terminal;
		while (!atomic_ptr_ptr->compare_exchange_weak(temp, n, storeOrder, loadOrder)) {
			while ((temp = atomic_ptr_ptr->load(reinterpret_cast<node*>(loadOrder))) == spin); //empty loop
			if (temp == terminal) { //start over
				atomic_ptr_ptr = &first;
				temp = terminal;
			} else {
				atomic_ptr_ptr = &temp->next;
				temp = terminal;
			}
		}
	}

	static bool remove_node(std::atomic<node*> & atomic_ptr, T & value, std::memory_order loadOrder, std::memory_order storeOrder) {
		node * x = owner_lock(atomic_ptr, loadOrder);
		if (x == terminal) {
			if (atomic_ptr.load(loadOrder) == terminal) return false;
			node * temp = terminal;
			owner_unlock(atomic_ptr, temp, storeOrder, loadOrder);
			return false;
		}
		value = x->value;
		node * y = owner_lock(x->next, loadOrder);
		owner_unlock(atomic_ptr, y, loadOrder, storeOrder);
		node * temp = terminal;
		owner_unlock(x->next, temp, loadOrder, storeOrder);
		decrement_reference_count(x, loadOrder, storeOrder);
		return true;
	}
};

#endif //FORWARD_LIST_C_HPP
