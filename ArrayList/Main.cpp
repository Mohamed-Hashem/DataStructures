#include "ArrayList.h"

int main()
{
	try
	{
		ArrayList<int> arr1;
		arr1.push_back(10);
		arr1.push_back(20);
		arr1.push_back(30);

		cout << " The Array 1: " << endl;
		for (int i = 0; i < arr1.size(); i++)
		{
			cout << arr1[i] << endl;
		}

		cout << "The Array 1 Size: " << arr1.size() << endl;

		cout << "============================================\n";

		ArrayList<int> arr2;

		arr2 = arr1; // deep copy and operator= overloading

		cout << "The Array 2: " << endl;

		for (int i = 0; i < arr2.size(); i++)
		{
			cout << arr2[i] << endl;
		}

		cout << "The Array 2 Size: " << arr2.size() << endl << endl;

		cout << "============================================ clear arr 2()\n";

		arr2.clear();

		cout << "The Array 2: " << endl;

		for (int i = 0; i < arr2.size(); i++)
		{
			cout << arr2[i] << endl;
		}

		cout << "The Array 2 Size: " << arr2.size() << endl << endl;

		cout << "============================================ resize arr 2()\n";

		arr2.resize(15);

		cout << "The Array 2: " << endl;

		for (int i = 0; i < arr2.size(); i++)
		{
			cout << arr2[i] << endl;
		}

		cout << "The Array 2 Size: " << arr2.size() << endl;
		cout << "The Array 2 Max Size: " << arr2.max_size() << endl << endl;

		cout << "============================================ 3 * pop_back()\n";

		arr1.pop_back();
		arr1.pop_back();
		arr1.pop_back();

		for (int i = 0; i < arr1.size(); i++)
		{
			cout << arr1[i] << endl;
		}

		cout << "The Array Size: " << arr1.size() << endl;

		cout << "============================================ pop_back()\n";

		try
		{
			arr1.pop_back(); // try to pop back from empty array

			for (int i = 0; i < arr1.size(); i++)
			{
				cout << arr1[i] << endl;
			}

			cout << "The Array Size: " << arr1.size() << endl;
		}
		catch (const exception& ext)
		{
			cout << ext.what() << endl;
		}

		cout << "\n\n ========= There's No Run Time Error =========\n";
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}
}