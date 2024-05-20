/**
 * pass in root as pointer, left and right as references
 * to a node pointer so we can modify them
 * (alternatively, we can return left and right pointers
 * as an std::pair)
 */
void split(Node *root, int x, Node *&left, Node *&right) {
	if (!root) {
		left = right = NULL;
		return;
	}
	if (root->val <= x) {
		split(root->right, x, root->right, right);
		left = root;
	} else {
		split(root->left, x, left, root->left);
		right = root;
	}
}
