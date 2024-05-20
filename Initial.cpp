int getpri() {return rand(0, MAX);}
struct Node {
	// the value and priority of the node respectively
	int val, weight;
	// Biến size là số lượng nút của cây
	int size;
	// pointer to left and right child (NULL means no child)
	Node *left, *right;
	Node(int val) : val(val), size(1), weight(getpri()), left(NULL), right(NULL){};
} *root;
