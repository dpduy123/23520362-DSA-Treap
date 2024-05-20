int getpri() {return rand(0, MAX);}
struct Node {
	// the value and weightority of the node respectively
	int val, weight;
	// pointer to left and right child (NULL means no child)
	Node *left, *right;
	Node(int val) : val(val), weight(getpri()), left(NULL), right(NULL){};
} *root;