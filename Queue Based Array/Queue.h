#include <iostream>
using namespace std;

template <class type>
class Queue
{
private:
	type* arr;
	int _front; // the index of the front element in the queue
	int rear; // the index of the last pushed element in the queue
	int max_size; // the max_size of the queue
	int capacity; // the number of elements in the queue

	void expand() {
		type* temp = new type[max_size * 2];

		for (int i = 0; i < max_size; i++) // copy the old array to the new one
			temp[i] = arr[i];

		delete arr; // delete the old array
		arr = temp; // make the new array the old one
		max_size = max_size * 2; // update the max_size
	}

	bool full() {
		return rear == max_size - 1;
	}

public:
	Queue() {
		max_size = 10;
		arr = new type[max_size];
		_front = 0; // why not -1? because we will use it as index in array and we will increment it before use it in array so we will start from 0
		rear = -1; // it is the last element in the queue so we will start from -1 and increment it before use it in array to save the first element in index 0 in array
		capacity = 0;
	}

	void push(type val) {
		if (full())
			expand();

		rear++;
		arr[rear] = val;
		capacity++;
	}

	void pop() {
		if (empty())
			throw invalid_argument("The Queue is Empty");

		_front++;
		capacity--;
	}

	bool empty() {
		return capacity == 0;
	}

	int size() {
		return capacity;
	}

	type front() {
		return arr[_front];
	}

	type back() {
		return arr[rear];
	}

	~Queue() {
		delete[] arr;
	}
};