/**
 * merge left and right pointers into root which
 * is a reference to a pointer to enable
 * modification within the function
 */
void merge(Node *&root, Node *left, Node *right) {
	if (!left || !right) {
		root = left ? left : right;
		return;
	}
	if (left->weight > right->weight) {
		merge(left->right, left->right, right);
		root = left;
	} else {
		merge(right->left, left, right->left);
		root = right;
	}
}