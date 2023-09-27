#include "Deque.h"

int main()
{
	try
	{
		Deque <int> q;

		q.push_back(10);
		q.push_back(20);
		q.push_back(30);
		q.push_back(40);
		q.push_back(50); // 10 20 30 40 50

		cout << "The Queue Element is : ";

		while (!q.empty()) {
			cout << q.front() << " ";
			q.pop_front();
		}

		cout << "\n\nSize of The Queue: " << q.size() << endl;

		q.push_back(5);  // 5
		q.push_back(10);
		q.push_back(15);
		q.push_back(20);
		q.push_back(30); // 5 10 15 20 30
		q.push_back(40);
		q.push_back(50); // 5 10 15 20 30 40 50
		q.push_back(60);
		q.push_back(70); // 5 10 15 20 30 40 50 60 70

		cout << "\nSize of The Queue: " << q.size() << endl;

		q.push_front(80); // 80 5 10 15 20 30 40 50 60 70
		q.push_front(90); // 90 80 5 10 15 20 30 40 50 60 70
		q.push_back(100); // 90 80 5 10 15 20 30 40 50 60 70 100

		cout << "\nSize of The Queue: " << q.size() << endl;

		q.pop_front(); // 80 5 10 15 20 30 40 50 60 70 100

		cout << "\nSize of The Queue: " << q.size() << endl;

		cout << "\nThe Queue Element is : ";

		while (!q.empty()) {
			cout << q.front() << " ";
			q.pop_front();
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