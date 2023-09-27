#include <iostream>
#include "Node.h"
using namespace std;

template <class type>
class Queue {
private:
	Node<type>* head;
	Node<type>* tail;
	int capacity;
public:
	Queue() {
		head = tail = nullptr;
		int capacity = 0;
	}

	void push(type val) {
		Node<type>* newNode = new Node<type>(val);

		if (empty())
			head = tail = newNode;
		else {
			tail->next = newNode;
			tail = newNode;
		}

		capacity++;
	}

	void pop() {
		if (empty())
			throw invalid_argument("You Can't Remove from empty List");

		Node<type>* temp = head->next;
		delete head;
		head = temp;

		capacity--;
	}

	type front() {
		if (empty())
			throw invalid_argument("There's No Elements");

		return head->val;
	}

	type back() {
		return tail->val;
	}

	int size() {
		return capacity;
	}

	bool empty() {
		if (capacity == 0)
			return true;
		else
			return false;
	}

	~Queue() {
		while (!empty())
			pop();
	}
};
