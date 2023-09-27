#include <iostream>
#include "Node.h"
using namespace std;

template <class type>
class DoubleLinkedList {
	Node<type>* head;
	Node<type>* last;
	int capacity;

public:
	DoubleLinkedList() {
		head = nullptr;
		last = nullptr;
		capacity = 0;
	}

	void erase(type val) {
		if (empty())
			throw invalid_argument("This List is Empty");
		else if (head->val == val && capacity == 1)
			clear();
		else if (head->val == val)
			pop_front();
		else {
			Node<type>* temp = head;

			while (temp->val != val && temp != nullptr && temp->next != nullptr) {
				temp = temp->next;
			}

			if (temp->val == val) {
				Node<type>* prevTemp = temp->prev;
				prevTemp->next = temp->next;
				temp->next->prev = prevTemp;
				delete temp;

				capacity--;

				if (capacity == 0)
					head = last = nullptr;
			}
			else
				throw invalid_argument("This Value is not in List");
		}
	}

	void insert(type val, int pos) {

		if (pos == 0)
			push_front(val);
		else {

			Node<type>* newNode = new Node<type>(val);
			Node<type>* temp = head;

			for (int i = 0; i < pos - 1 && temp->next != nullptr; i++) {
				temp = temp->next;
			}

			if (temp->next == nullptr)
				push_back(val);
			else {
				Node<type>* T2 = temp->next;
				temp->next = newNode;
				newNode->prev = temp;
				newNode->next = T2;
				T2->prev = newNode;
				capacity++;
			}
		}
	}

	bool find(type val) {

		Node<type>* temp = head;

		while (temp != nullptr && temp->next != nullptr)
		{
			if (temp->val == val)
				return true;
		}

		return false;
	}

	void pop_front() {

		if (empty())
			throw invalid_argument("This List is Empty");
		else if (capacity == 1 && head->next == nullptr) {
			clear();
		}
		else {
			Node<type>* temp = head->next;
			temp->prev = nullptr;
			delete head;
			head = temp;
			capacity--;

			if (capacity == 1)
				last = head;
		}
	}

	void pop_back() {

		if (empty())
			throw invalid_argument("This List is Empty");
		else if (capacity == 1 && head->next == nullptr) {
			clear();
		}
		else {
			Node<type>* temp = last->prev;
			temp->next = nullptr;
			delete last;
			last = temp;
			capacity--;

			if (capacity == 1)
				head = last;
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
			newNode->prev = last;
			last = newNode;
		}

		capacity++;
	}

	void push_front(type val) {
		Node<type>* newNode = new Node<type>(val);

		if (empty())
			head = last = newNode;
		else
		{
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}

		capacity++;
	}

	int size() {
		return capacity;
	}

	Node<type>* begin() {
		if (empty())
			throw invalid_argument("This List is Empty");
		else
			return head;
	}

	Node<type>* end() {
		if (empty())
			throw invalid_argument("This List is Empty");
		else
			return last->next;
	}

	void merge(const DoubleLinkedList<type>& sl2) {
		Node<type>* temp = sl2.head;

		while (temp != nullptr)
		{
			push_back(temp->val);
			temp = temp->next;
		}
	}

	void reverse() { // reverse list by changing pointers direction without changing values of nodes and without using extra memory
		Node<type>* temp = last;

		while (temp != this->begin() && temp->prev != nullptr) {
			cout << temp->val << " ==> ";
			temp = temp->prev;
		}

		if (temp == this->begin())
			cout << temp->val << "\t #" << endl;
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

	~DoubleLinkedList() {
		clear();
	}
};
