template <class type>
struct Node {
	type val;
	Node<type>* next;

	explicit Node(type v) { // 
		val = v;
		next = nullptr;
	}
};