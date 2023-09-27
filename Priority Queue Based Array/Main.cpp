#include "Priority_Queue.h"

int main()
{
	Priority_Queue <int> q;
	try
	{
		q.push(3);
		q.push(6);
		q.push(5);
		q.push(4);
		q.push(3);
		q.push(6);
		q.push(5);
		q.push(4);
		q.push(3);
		q.push(6);
		q.push(5);
		q.push(4);

		cout << "The Size of Priority Queue : " << q.size() << endl;

		cout << "The Elements in the Priority Queue : ";

		while (!q.empty()) {
			cout << q.front() << " ";
			q.pop();
		}

		cout << "\nThe Size of Priority Queue : " << q.size() << endl;
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}

	return 0;
}