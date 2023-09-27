#include "Queue.h"

int main()
{
	try
	{
		Queue<int> q;
		q.push(5);
		q.push(15);
		q.push(25);
		q.push(35);
		q.push(45);
		q.push(55);
		q.push(65);
		q.push(75);
		q.push(85);
		q.push(95);

		cout << "Queue Size: " << q.size() << endl;

		cout << "Queue Elements: ";

		while (!q.empty()) {
			cout << q.front() << " ";
			q.pop();
		}

		cout << "\n\n========= NO Run Time Error =========\n";
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}
}