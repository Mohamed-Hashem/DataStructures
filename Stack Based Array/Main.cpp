#include "Stack.h"

int main()
{
	try
	{
		Stack<int> stk;
		stk.push(5);
		stk.push(15);
		stk.push(20);
		stk.push(25);
		stk.push(35);

		while (!stk.empty()) {
			cout << stk.top() << endl;
			stk.pop();
		}

		cout << "\nThe Stack is : " << (stk.empty() ? "Empty" : "Not Empty") << endl;
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}
}