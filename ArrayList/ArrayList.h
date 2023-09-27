#include <iostream>
using namespace std;

template <class T>
class ArrayList {
	T* arr;
	int capacity; // the actual size of the array
	int max_capacity; // the max size of the array

	void expand_capacity() {
		T* temp = new T[max_capacity++];

		for (int i = 0; i < capacity; i++)
			temp[i] = arr[i];

		delete[] arr;
		arr = temp; // we make an overloaded operator= to make a deep copy
		delete[] temp;
	}

	bool full() {
		if (capacity == max_capacity - 1)
			return true;
		else
			return false;
	}

public:
	ArrayList() {
		resize();
	}

	ArrayList(int n) {
		resize(n);
	}

	bool empty() {
		if (capacity == 0)
			return true;
		else
			return false;
	}

	void push_back(T val) {
		if (full())
			expand_capacity();

		arr[capacity] = val;
		capacity++;
	}

	void push_front(T val) {

		if (full())
			expand_capacity();

		for (int i = capacity; i >= 1; i--) // shift all elements above index
			arr[i] = arr[i - 1];

		arr[0] = val;
		capacity++;
	}

	void pop_back() {
		if (empty())
			throw underflow_error("You can't remove element for the Array because it's Empty");
		else
			capacity--;
	}

	void pop_front() {
		if (empty())
			throw underflow_error("You can't remove element for the Array because it's Empty");
		else {

			for (int i = 0; i < capacity - 1; i++)
			{
				arr[i] = arr[i + 1];
			}

			capacity--;
		}
	}

	void clear() {
		capacity = 0;
		max_capacity = 0;
		delete[] arr;
	}

	void resize(int n = 10) { // resize the array to n size
		capacity = 0;
		max_capacity = n;
		arr = new T[max_capacity]{}; // we make an overloaded operator= to make a deep copy
	}

	int size() { // return the actual size of the array
		return capacity;
	}

	int max_size() { // return the max size of the array
		return max_capacity;
	}

	T front() {
		if (capacity > 0)
			return arr[0];
		else
			throw invalid_argument("There's no Element in Array");
	}

	T back() { // return the last element in the array
		if (capacity > 0)
			return arr[capacity - 1];
		else
			throw invalid_argument("There's no Element in Array");
	}

	T operator [](int i) { // return the value of the index
		if (i < 0 || i >= capacity)
			throw out_of_range("The Index is Out of Range");
		else
			return arr[i];
	}

	void erase(T n) { // remove the value from the array

		if (empty())
			throw out_of_range("You can't remove element for the Array because it's Empty");

		int index = -1; // initial value if the value is not found

		for (int i = 0; i < capacity; i++)
		{
			if (arr[i] == n) {
				index = i;
				break;
			}
		}

		if (index != -1) {

			for (int i = index; i < capacity - 1; i++)
				arr[i] = arr[i + 1];

			capacity--;
		}
		else
			throw invalid_argument("This Value is not Found");
	}

	int find(int val) { // return true if the value is found in the array
		for (int i = 0; i < capacity; i++)
		{
			if (arr[i] == val)
				return i;
		}

		return -1;
	}

	ArrayList<T>& operator=(ArrayList<T> rightArray) { // deep copy
		capacity = rightArray.size();
		max_capacity = rightArray.max_size();

		arr = new T[max_capacity];

		for (int i = 0; i < capacity; i++)
			arr[i] = rightArray.arr[i];

		return *this;
	}
};
