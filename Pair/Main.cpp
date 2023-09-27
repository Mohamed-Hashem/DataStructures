#include "Pair.h"

int main()
{
	try
	{
		Pair <int, int> pr;
		pr.first = 1;
		pr.second = 10;

		cout << pr.first << " " << pr.second << endl;
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}

	return 0;
}