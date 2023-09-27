#include <iostream>
#include "Node.h"
using namespace std;

template <class type>
class SingleLinkedList {
	Node<type>* head;
	int capacity;

public:
	SingleLinkedList() {
		head = nullptr;
		capacity = 0;
	}

	bool erase(type val) { // erase the first node with the value val
		if (capacity == 0)
			throw invalid_argument("This List is Empty");
		else if (head->val == val && capacity == 1)
			clear();
		else if (head->val == val)
			pop_front();
		else {
			Node<type>* current = head;
			Node<type>* prev = current;

			while (current != nullptr && current->next != nullptr && current->val != val) {
				prev = current;
				current = current->next;
			}

			if (current->val == val) {
				prev->next = current->next;
				delete current;
			}
			else
				throw invalid_argument("This Value is Not Found in List");

			capacity--;
		}
	}

	void insert(type val, int pos) {

		if (pos == 0)
			push_front(val);
		else {
			Node<type>* newNode = new Node<type>(val);
			Node<type>* temp = head;

			for (int i = 0; i < pos - 1 && temp->next != nullptr; i++) // pos - 1 because we want to stop at the node before the position we want to insert at and temp->next != nullptr because we want to stop at the last node in the list
			{
				temp = temp->next;
			}

			Node<type>* nextNode = temp->next; // nextNode is the node after the position we want to insert at
			temp->next = newNode;
			newNode->next = nextNode;

			capacity++;
		}
	}

	Node<type>* find(type val) {

		Node<type>* temp = head;

		while (temp != nullptr && temp->next != nullptr)
		{
			if (temp->val == val)
				return temp;
		}

		return nullptr;
	}

	void pop_front() {

		if (capacity == 0)
			throw invalid_argument("This List is Empty");
		else if (capacity == 1 && head->next == nullptr)
			clear();
		else {
			Node<type>* temp = head;
			head = head->next;
			delete temp;
			capacity--;
		}
	}

	void pop_back() {

		if (capacity == 0)
			throw invalid_argument("This List is Empty");
		else if (capacity == 1 && head->next == nullptr)
			clear();
		else {
			Node<type>* current = head;
			Node<type>* prev = current;

			while (current != nullptr && current->next != nullptr) {
				prev = current;
				current = current->next;
			}

			prev->next = nullptr;
			delete current;

			capacity--;
		}
	}

	void push_back(type val) {

		Node<type>* newNode = new Node<type>(val);

		if (head == nullptr && capacity == 0)
			head = newNode;
		else {
			Node<type>* temp = head;

			while (temp != nullptr && temp->next != nullptr)
				temp = temp->next;

			temp->next = newNode;
		}

		capacity++;
	}

	void push_front(type val) {

		Node<type>* newNode = new Node<type>(val);

		if (empty())
			head = newNode;
		else
		{
			newNode->next = head;
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
		else {
			Node <type>* temp = head;

			while (temp != nullptr) // while temp != nullptr because we want to stop at the last node in the list
				temp = temp->next;

			return temp;
		}
	}

	void merge(const SingleLinkedList<type>& sl2) {

#pragma region First Solution

		Node<type>* temp = sl2.head;

		while (temp != nullptr)
		{
			push_back(temp->val);
			temp = temp->next;
		}

#pragma endregion

#pragma region Second Solution
		//Node<type>* temp = begin();

		//while (temp != nullptr && temp->next != nullptr)
		//	temp = temp->next;

		//temp->next = sl2.head;
		//this->capacity = this->capacity + sl2.capacity;
#pragma endregion

	}

	bool empty() {
		return capacity == 0 && head == nullptr;
	}

	void clear() { // clear() is a function that deletes all nodes in the list

		Node<type>* temp = head;

		while (temp != nullptr) { // while temp != nullptr because we want to delete all nodes in list
			head = head->next;
			delete temp;
			temp = head;
		}

		delete temp;

		capacity = 0;
		head = nullptr;
	}

	~SingleLinkedList() {
		clear();
	}
};
