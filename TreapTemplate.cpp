#include <bits/stdc++.h> 

using namespace std;

#define int long long 
#define pii pair <int,int> 
#define st first 
#define nd second 
#define vi vector <int> 
#define vpii vector <pii> 
#define pb push_back 
#define lb lower_bound 
#define ub upper_bound 
#define FILE ""
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r) { return uniform_int_distribution<int>(l, r)(rd); }

const int oo = 1e18;
const int base = 311;
const int mod = 998244353;

const int N = 1e6 + 6;
const int MAX = 2e9;

int getpri() {return rand(0, MAX);}
struct Node {
	// the value and weightority of the node respectively
	int val, weight;
	// pointer to left and right child (NULL means no child)
	Node *left, *right;
	Node(int val) : val(val), weight(getpri()), left(NULL), right(NULL){};
} *root;

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

void print(Node *cur) {
	if (!cur) return;
	print(cur->left);
	cout << cur->val;
	print(cur->right);
}

void input()
{
	
}	

void solve()
{
	
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T = 1;
	//cin >> T;
	while (T--) 
	{
		input();
		solve();
	}
	return 0;
}
/*
From Benq: 
	int overflow?
	array bounds?
	Special Cases (n = 1?)
	Do something instead of nothing and stay organized 
	WRITE STUFF DOWN 
	DON'T GET STUCK ON ONE APPROACH 
*/