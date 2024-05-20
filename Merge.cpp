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
	root->size = 1 + size(root->left) + size(root->right);
}
