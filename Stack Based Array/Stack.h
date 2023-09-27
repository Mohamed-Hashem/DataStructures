#include <iostream>
using namespace std;

template <class T>
class Stack {
	T top_value;
	T* arr;
	int size;

	void expand() { // O(n) time complexity and O(n) space complexity 
		T* temp = new T[size * 2];

		for (int i = 0; i < size; i++) {
			temp[i] = arr[i];
		}

		delete[] arr;
		arr = temp;
		size *= 2;
	}

public:
	Stack() {
		top_value = -1;
		size = 10;
		arr = new T[size];
	}

	void push(T x) { // 
		if (top_value >= size - 1) {
			throw overflow_error("Stack Overflow");
		}
		else {

			if (top_value == size - 1)
				expand();

			top_value++;
			arr[top_value] = x;
		}
	}

	T pop() {
		if (top_value < 0) {
			throw underflow_error("Stack Underflow");
		}
		else {
			top_value--;
			T x = arr[top_value];
			return x;
		}
	}

	T top() {
		T x = arr[top_value];
		return x;
	}

	bool empty() {
		return (top_value < 0);
	}
};