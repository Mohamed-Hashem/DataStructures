template <class type>
struct Node {
	type val;
	Node* next;

	explicit Node(type val) { // explicit to prevent implicit conversion and prevent the compiler from using this constructor in unexpected ways
		this->val = val;
		next = nullptr;
	}
};