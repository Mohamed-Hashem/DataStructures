#include "DoubleEndedList.h"

template <class type>
class Queue {
private:
	DoubleEndedList<type> list;

public:
	Queue() {
		list.clear();
	}
	void push(type val) {
		list.push_back(val);
	}

	void pop() {
		list.pop_front();
	}

	type front() {
		return list.front()->val;
	}

	type back() {
		return list.back()->val;
	}

	int size() {
		return list.size();
	}

	bool empty() {
		return list.empty();
	}

	~Queue() {
		list.clear();
	}
};