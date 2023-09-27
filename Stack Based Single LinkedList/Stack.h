#include "SingleLinkedList.h"

template <class type>
class Stack : protected SingleLinkedList <type> {
public:
	Stack() = default;

	void push(type val) {
		this->push_front(val);
	}

	void pop() {
		this->pop_front();
	}

	int size() {
		return SingleLinkedList<type>::size();
	}

	bool empty() {
		return SingleLinkedList<type>::empty();
	}

	type top() {
		Node<type>* be = this->begin();
		return be->val;
	}
};