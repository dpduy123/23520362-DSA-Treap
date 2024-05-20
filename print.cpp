void print(Node *cur) {
	if (!cur) return;
	print(cur->left);
	cout << cur->val;
	print(cur->right);
}