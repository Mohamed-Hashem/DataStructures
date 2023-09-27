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

	bool full() {
		return capacity == max_size - 1;
	}

public:
	Queue() {
		max_size = 10;
		arr = new type[max_size];
		_front = 0; // why not -1? because we will use it as index in array and we will increment it before use it in array so we will start from 0
		rear = -1; // it is the last element in the queue so we will start from -1 and increment it before use it in array to save the first element in index 0 in array
		capacity = 0;
	}

	Queue(int siz) {
		max_size = siz + 1;
		arr = new type[max_size];
		_front = 0; // why not -1? because we will use it as index in array and we will increment it before use it in array so we will start from 0
		rear = -1; // it is the last element in the queue so we will start from -1 and increment it before use it in array to save the first element in index 0 in array
		capacity = 0;
	}

	void push(type val) {
		if (full())
			throw overflow_error("The Queue is Full");
		else if (rear == max_size - 1)
			rear = -1;

		rear++;
		arr[rear] = val;
		capacity++;
	}

	void pop() {
		if (empty())
			throw underflow_error("The Queue is Empty");
		else if (_front == max_size - 1)
			_front = 0;
		else
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