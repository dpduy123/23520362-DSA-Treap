Node *find(Node *root, int key) {
	if (!root) return nullptr;
    if (key > root->key) return find(root -> right, key);	   
   	if (key < root->key) return find(root -> left, key);
	return root;
}
