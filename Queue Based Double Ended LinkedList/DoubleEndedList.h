#include <iostream>
#include "Node.h"
using namespace std;

template <class type>
class DoubleEndedList {
private:
	Node<type>* head;
	Node<type>* last;
	int capacity;

public:
	DoubleEndedList() {
		head = nullptr;
		last = nullptr;
		capacity = 0;
	}

	void pop_front() {

		if (empty())
			throw invalid_argument("This List is Empty");
		else if (capacity == 1 && head->next == nullptr) {
			clear();
		}
		else {
			Node<type>* temp = head->next;
			delete head;
			head = temp;
			capacity--;

			if (capacity == 1)
				last = head;
		}
	}

	bool empty() {
		if (capacity == 0 && last == nullptr && head == nullptr)
			return true;
		else
			return false;
	}

	void push_back(type val) {
		Node<type>* newNode = new Node<type>(val);

		if (empty())
			head = last = newNode;
		else {
			last->next = newNode;
			last = newNode;
		}

		capacity++;
	}

	int size() {
		return capacity;
	}

	Node<type>* front() {
		if (empty())
			throw invalid_argument("This List is Empty");
		else
			return head;
	}

	Node<type>* back() {
		if (empty())
			throw invalid_argument("This List is Empty");
		else
			return last;
	}

	void clear() {
		Node<type>* temp = head;

		while (temp != nullptr) { // while temp != nullptr because we want to delete all nodes in list
			head = head->next;
			delete temp;
			temp = head;
		}

		delete temp;
		capacity = 0;
		head = last = nullptr;
	}

	~DoubleEndedList() {
		clear();
	}
};
