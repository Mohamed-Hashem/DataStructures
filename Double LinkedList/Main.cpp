#include "DoubleLinkedList.h"

int main()
{
	try
	{
		DoubleLinkedList<int> dll1;
		dll1.push_back(5);
		dll1.push_back(15);
		dll1.push_back(25);
		dll1.push_back(35);

		for (auto it = dll1.begin(); it != dll1.end(); it = it->next) {
			cout << it->val << " ";
		}

		cout << "\n==================== push_front(0) \n";

		dll1.push_front(0);

		for (auto it = dll1.begin(); it != dll1.end(); it = it->next) {
			cout << it->val << " ";
		}

		cout << "\n==================== dll1.pop_back();\n";

		dll1.pop_back();

		for (auto it = dll1.begin(); it != dll1.end(); it = it->next) {
			cout << it->val << " ";
		}

		cout << "\n==================== dll1.pop_front(); \n";

		dll1.pop_front();

		for (auto it = dll1.begin(); it != dll1.end(); it = it->next) {
			cout << it->val << " ";
		}


		cout << "\n==================== dll1.insert(55, 0) & dll1.insert(45, 12); \n";

		dll1.insert(55, 0);

		dll1.insert(45, 12);

		for (auto it = dll1.begin(); it != dll1.end(); it = it->next) {
			cout << it->val << " ";
		}

		cout << "\n==================== dll1.erase(5);\n";

		dll1.erase(5);

		for (auto it = dll1.begin(); it != dll1.end(); it = it->next) {
			cout << it->val << " ";
		}

		cout << "\n==================== DoubleLinkedList Sl2 \n";

		DoubleLinkedList<int> dll2;
		dll2.push_back(1);
		dll2.push_back(11);
		dll2.push_back(111);
		dll2.push_back(1111);

		for (auto it = dll2.begin(); it != dll2.end(); it = it->next) {
			cout << it->val << " ";
		}

		cout << "\n==================== Merge Between Sl1 and Sl2 \n";

		dll1.merge(dll2);

		for (auto it = dll1.begin(); it != dll1.end(); it = it->next) {
			cout << it->val << " ";
		}

		cout << "\nSize " << dll1.size();

		cout << "\n==================== reverse\n";

		dll1.reverse();

		cout << "\n==================== Clear\n";

		dll1.clear();

		cout << "\nSize For DDL 1 = " << dll1.size() << endl;

		cout << "\nSize For DDL 2 = " << dll2.size() << endl;

		cout << "\n\nNO Run Time Error\n";
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}