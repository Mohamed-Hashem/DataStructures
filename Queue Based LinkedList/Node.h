template <class type>
struct Node {
	type val;
	Node* next;

	Node(type v) {
		val = v;
		next = nullptr;
	}
};