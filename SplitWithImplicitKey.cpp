void split(Node *treap, Node *&left, Node *&right, int val, int add = 0) {
	if (!treap) {
		left = right = NULL;
		return;
	}

	int cur_size = add + size(treap->left);  // implicit key
	if (cur_size < val) {
		split(treap->right, treap->right, right, key,
		      add + 1 + size(treap->left));
		left = treap;
	} else {
		split(treap->left, left, treap->left, key, add) right = treap;
	}
	treap->size = 1 + size(treap->left) + size(treap->right);
}