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
struct Node{
	char val;
	int size, weight;
	bool inv;
	Node *left, *right;
	Node() {}
	Node(char val) : val(val), size(1), weight(getpri()), inv(0), left(0), right(0) {};
} *root;

int size(Node *cur) {return cur ? cur->size : 0;}

void pushdown(Node *cur) 
{
	/*
	LazyUpdate
	*/
	if (!cur) return;
	if (!cur->inv) return;
	swap(cur->left, cur->right);
	if (cur->left) cur->left->inv ^= 1;
	if (cur->right) cur->right->inv ^= 1;
	cur->inv = 0;
}

void split(Node *cur, Node *&l, Node *&r, int key, int add)
{
	pushdown(cur);
	if (!cur) 
	{
		l = r = NULL;
		return;
	}
	int curkey = size(cur->left) + add;
	if (curkey > key) 
	{
		split(cur->left, l, cur->left, key, add);
		r = cur;
	}
	else 
	{
		split(cur->right, cur->right, r, key, add + size(cur->left) + 1);
		l = cur;
	}
	cur->size = size(cur->left) + size(cur->right) + 1;
}

void merge(Node *&cur, Node *l, Node *r) 
{
	pushdown(l);
	pushdown(r);
	if (!l || !r) 
	{
		cur = l? l : r;
		return;
	}
	if (l->weight > r->weight) 
	{
		merge(l->right, l->right, r);
		cur = l;
	}
	else 
	{
		merge(r->left, l, r->left);
		cur = r;
	}
	cur->size = size(cur->left) + size(cur->right) + 1;
}

void print(Node *cur) {
	pushdown(cur);
	if (!cur) return;
	print(cur->left);
	cout << cur->val;
	print(cur->right);
}
char c;
int n, m;
void input()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
	{
		cin >> c;
		merge(root, root, new Node(c));
	}
}	

void solve()
{
	while (m--) 
	{
		int l, r;
		cin >> l >> r;
		Node *a, *b, *c, *d;
		split(root, a, b, r - 1, 0);
		split(a, c, d, l - 2, 0);
		d->inv ^= 1;
		merge(root, c, d);
		merge(root, root, b);
	}
	print(root);
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
