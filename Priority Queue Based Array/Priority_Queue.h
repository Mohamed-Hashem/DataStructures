#include <iostream>
using namespace std;

template <class type>
class Priority_Queue
{
private:

	type* arr;
	int _front;
	int rear;
	int capacity;
	int max_size;

	bool full() {
		return capacity == max_size - 1;
	}

	void expand() {
		type* temp = new type[max_size * 2];

		for (int i = 0; i < max_size; i++) {
			temp[i] = arr[i];
		}

		delete[] arr;
		arr = temp;
		max_size *= 2;
	}

public:
	Priority_Queue() {
		max_size = 10;
		arr = new type[max_size];
		_front = 0;
		rear = -1;
		capacity = 0;
	}

	Priority_Queue(int _size) {
		max_size = _size;
		arr = new type[max_size];
		_front = 0;
		rear = -1;
		capacity = 0;
	}

	void push(type val) {
		if (full() || empty()) {
			expand();
			rear++;
			arr[rear] = val;
		}
		else {
			int i = rear + 1;

			while (val > arr[i - 1] && i > _front) {
				arr[i] = arr[i - 1];
				i--;
			}

			arr[i] = val;
			rear++;
		}

		capacity++;
	}

	void pop() {
		if (empty()) {
			throw underflow_error("The Priority Queue is Empty");
		}

		_front++;
		capacity--;
	}

	int size() {
		return capacity;
	}

	type front() {
		if (empty()) {
			throw underflow_error("The Priority Queue is Empty");
		}

		return arr[_front];
	}

	type back() {
		if (empty())
			throw underflow_error("The Priority Queue is Empty");

		return arr[rear];
	}

	bool empty() {
		if (capacity == 0)
		{
			_front = 0;
			rear = -1;
			return true;
		}
		else
			return false;
	}

	~Priority_Queue() {
		delete[] arr;
	}
};

