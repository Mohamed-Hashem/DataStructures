#include "SingleLinkedList.h"

int main()
{
	try
	{
		SingleLinkedList<int> sl1;
		sl1.push_back(5);
		sl1.push_back(15);
		sl1.push_back(25);
		sl1.push_back(35);

		for (auto it = sl1.begin(); it != sl1.end(); it = it->next) {
			cout << it->val << endl;
		}

		cout << "==================== push_front(0)\n";

		sl1.push_front(0);

		for (auto it = sl1.begin(); it != sl1.end(); it = it->next) {
			cout << it->val << endl;
		}

		sl1.pop_back();

		cout << "==================== sl.pop_front();\n";

		for (auto it = sl1.begin(); it != sl1.end(); it = it->next) {
			cout << it->val << endl;
		}

		cout << "==================== sl.insert(45, 12);\n";

		for (auto it = sl1.begin(); it != sl1.end(); it = it->next) {
			cout << it->val << endl;
		}

		cout << "==================== sl.erase(5);\n";

		for (auto it = sl1.begin(); it != sl1.end(); it = it->next) {
			cout << it->val << endl;
		}

		cout << "==================== Initialize new Linked List\n";

		SingleLinkedList<int> sl2;
		sl2.push_back(1);
		sl2.push_back(11);
		sl2.push_back(111);
		sl2.push_back(1111);

		for (auto it = sl2.begin(); it != sl2.end(); it = it->next) {
			cout << it->val << endl;
		}

		cout << "==================== Merge Two Linked List\n";

		sl1.merge(sl2);

		for (auto it = sl1.begin(); it != sl1.end(); it = it->next) {
			cout << it->val << endl;
		}

		cout << "==================== Print the Second List\n";

		for (auto it = sl2.begin(); it != sl2.end(); it = it->next) {
			cout << it->val << endl;
		}

		cout << "==================== sl.clear();\n";

		sl1.clear();

		cout << "Size of First List: " << sl1.size() << endl;

		cout << "\n\nThere's No Run Time Error\n";
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}