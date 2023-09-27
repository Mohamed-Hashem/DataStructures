template <class type>
struct Node {
	type val;
	Node<type>* next;
	Node<type>* prev;

	explicit Node(type v) { // 
		val = v;
		next = nullptr;
		prev = nullptr; /////// add prev Pointer
	}
};