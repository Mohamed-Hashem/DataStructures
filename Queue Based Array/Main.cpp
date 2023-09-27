#include "Queue.h"

int main()
{
	try
	{
		Queue <int> q;
		q.push(10);
		q.push(20);
		q.push(30);
		q.push(40);
		q.push(50);

		cout << "The Queue Element is : ";
		while (!q.empty()) {
			cout << q.front() << " ";
			q.pop();
		}

		cout << "\n\nSize of The Queue: " << q.size() << endl;

		q.push(5);
		q.push(10);
		q.push(15);
		q.push(20);
		q.push(30);
		q.push(40);
		q.push(50);
		q.push(60);
		q.push(70);
		cout << "\nSize of The Queue: " << q.size() << endl;

		q.push(80);

		cout << "\nSize of The Queue: " << q.size() << endl;

		cout << "\nThe Queue Element is : ";

		while (!q.empty()) {
			cout << q.front() << " ";
			q.pop();
		}

		cout << "\nSize of The Queue: " << q.size() << endl;

		cout << "\n========= There's No Run Time Error	=========" << endl;
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}

	return 0;
}