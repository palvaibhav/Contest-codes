/* -------------------------------------------------

Author :- Vaibhav Pal
College :- Northern India Engineering College, New Delhi
Coding Handle :- underdog_eagle
Title :- Use of BinaryTrie for solving Maximum Subarray XOR problem in O(N*lgN)

----------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define INF 1000000000000000000          // 10^18
#define nl '\n'
#define sp ' '
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
#define fo(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)

const int INT_SIZE = 32; // change this and Integer type in Binary Trie class according to the problem.

class Node {
public:
	Node* arr[2];
	Node() {
		this->arr[0] = NULL;
		this->arr[1] = NULL;
	}
};

class BinaryTrie {
private:
	Node* root;
	
	// Insert Func is same for all problems.
	Node* insertUtil(Node* root, int num, int lvl) {
		if (lvl == -1)
			return root;
		bool bit = num & (1 << lvl);
		if (root->arr[bit] == NULL) {
			root->arr[bit] = new Node();
			root->arr[bit] = insertUtil(root->arr[bit], num, lvl - 1);
			return root;
		}
		else {
			root->arr[bit] = insertUtil(root->arr[bit], num, lvl - 1);
			return root;
		}
	}

	int queryUtil(Node* root, int num, int curRes, int lvl) {
		if (lvl == -1) 
			return curRes;
		bool bit = num & (1 << lvl);
		if (root->arr[!bit] != NULL) {
			if (!bit) curRes = curRes | (1 << lvl);
			return queryUtil(root->arr[!bit], num, curRes, lvl - 1);
		}
		else {
			if (bit) curRes = curRes | (1 << lvl);
			return queryUtil(root->arr[bit], num, curRes, lvl - 1);
		}
	}

public:	
	BinaryTrie() {
		this->root = new Node();
	}

	void insert(int num) {
		this->root = insertUtil(this->root, num, INT_SIZE - 1);
	}

	int query(int pre) {
		return (pre ^ queryUtil(this->root, pre, 0, INT_SIZE - 1));// Using the property F[L, R] = F[1, R] xor F[1, L-1]
	}

};

int main()
{
	FAST_IO
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vi arr(n);
		fo(i, 0, n - 1) cin >> arr[i];
		int ans = 0;
		int pre = 0;
		BinaryTrie tr;
		tr.insert(pre);
		fo(i, 0, n - 1) {
			pre = (pre ^ arr[i]);
			tr.insert(pre);
			ans = max(ans, tr.query(pre));
		}
		//delete &tr;
		cout << ans << nl;
	}

	//system("pause");
	return 0;
}