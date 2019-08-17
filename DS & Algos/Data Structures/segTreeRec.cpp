#include <bits/stdc++.h>

using namespace std;

struct Node {
	int x;
};

struct SegTree {
	vector<Node> t;
	int n;
	
	SegTree(vector<int>& v) {
		n = (int)v.size();
		t.resize(4 * n);
		build(1, 0, n - 1, v);
	}
	
	void build(int p, int l, int r, vector<int>& v) {
		if (l == r) {
			t[p].x = v[l];
		} else {
			int pl = p << 1, pr = p << 1 | 1, mid = (l + r) >> 1;
			build(pl, l, mid, v);
			build(pr, mid + 1, r, v);
			t[p] = combine(t[pl], t[pr]);
		}
	}
	
	void update(int p, int l, int r, int i, int j, int val) {
		if (j < l || r < i) {
			return;
		} 
		if (i <= l && r <= j) {
			t[p].x = val;
			return;
		} 
		int pl = p << 1, pr = p << 1 | 1, mid = (l + r) >> 1;
		update(pl, l, mid, i, j, val);
		update(pr, mid + 1, r, i, j, val);
		t[p] = combine(t[pl], t[pr]);
	}
	
	Node query(int p, int l, int r, int i, int j) {
		if (j < l || r < i) {
			Node res;
			res.x = INT_MAX;
			return res;
		} 
		if (i <= l && r <= j) {
			return t[p];
		} 
		int pl = p << 1, pr = p << 1 | 1, mid = (l + r) >> 1;
		Node al = query(pl, l, mid, i, j);
		Node ar = query(pr, mid + 1, r, i, j);
		return combine(al, ar);
	}
	
	Node combine(Node& a, Node& b) {
		Node c;
		c.x = min(a.x, b.x);
		return c;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<int> v = {0, 3, 1, 4, 4, 10, -3, 20, 5, 8, 11, 12};
	SegTree A(v);
	cout << A.query(1, 0, 11, 1, 5).x << "\n";	
	return 0;
}
