#include <iostream>
#include "Node.h"
using namespace std;

template <class type>
class Stack {
private:
	Node<type>* head;
	int capacity;

public:
	Stack() {
		head = nullptr;
		capacity = 0;
	}

	void push(type val) {
		Node<type>* newNode = new Node<type>(val);

		if (empty()) {
			head = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}

		capacity++;
	}

	void pop() {

		if (empty())
			throw invalid_argument("There's No Elements to Remove");
		else
		{
			Node<type>* temp = head->next;
			delete head;
			head = temp;
		}

		capacity--;
	}

	int size() {
		return capacity;
	}

	bool empty() {
		return head == nullptr && capacity == 0;
	}

	type top() {
		return head->val;
	}
};
