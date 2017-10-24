/* -------------------------------------------------

Author :- Vaibhav Pal
College :- Northern India Engineering College, New Delhi
Coding Handle :- underdog_eagle
Title :- Use of BinaryTrie for finding count of
		 Subarrays with XOR sum less than K in O(N*lgN).

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
	Node* child[2]; // Pointers to Left and Right Child : 0 idx means left and 1 idx means right.
	int leafCnt[2]; // No. of leaf nodes when we go towards left and right child from current node.
	Node() {
		this->child[0] = NULL;
		this->child[1] = NULL;
		this->leafCnt[0] = 0;
		this->leafCnt[1] = 0;
	}
};

class BinaryTrie {
private:
	Node* root; // root of the Trie DS.
	
	Node* insertUtil(Node* root, int num, int lvl) {
		if (lvl == -1) {
			root->leafCnt[0]++;
			return root;
		}
		bool bit = num & (1 << lvl);
		if (root->child[bit] == NULL) {
			root->child[bit] = new Node();
			root->child[bit] = insertUtil(root->child[bit], num, lvl - 1);
			root->leafCnt[bit] = (root->child[bit]->leafCnt[0] + root->child[bit]->leafCnt[1]);
			return root;
		}
		else {
			root->child[bit] = insertUtil(root->child[bit], num, lvl - 1);
			root->leafCnt[bit] = (root->child[bit]->leafCnt[0] + root->child[bit]->leafCnt[1]);
			return root;
		}
	}

	int queryUtil(Node* root, int pre, int k, int lvl) {
		if (lvl == -1 || root == NULL) // Base case.
			return 0;
		bool preBit = pre & (1 << lvl);
		bool kBit = k & (1 << lvl);
		// Comparing pre and K bits :-
		if (kBit) {
			if(!preBit) // (preBit == 0 && kBit == 1) means include all leafs in the left subtree + query on right subtree.
				return root->leafCnt[0] + queryUtil(root->child[1], pre, k, lvl - 1);
			else // (preBit == 1 && kBit == 1) means include all leafs in the right subtree + query on left subtree.
				return root->leafCnt[1] + queryUtil(root->child[0], pre, k, lvl - 1);
		}
		else {
			if (!preBit) // (preBit == 0 && kBit == 0) means exclude right subtree and query on left subtree.
				return queryUtil(root->child[0], pre, k, lvl - 1);
			else // (preBit == 1 && kBit == 0) means exclude left subtree and query on right subtree.
				return queryUtil(root->child[1], pre, k, lvl - 1);
		}
			
	}

public:	
	BinaryTrie() {
		this->root = new Node();
	}

	void insert(int num) {
		this->root = insertUtil(this->root, num, INT_SIZE - 1);
	}

	int query(int pre, int k) {
		return queryUtil(this->root, pre, k, INT_SIZE - 1);
	}

};

int main()
{
	FAST_IO
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vi arr(n);
		fo(i, 0, n - 1) cin >> arr[i];

		ll ans = 0;
		int pre = 0; // This will store prefix Xor sum starting from idx 0.
		BinaryTrie tr; // Create new BinaryTrie DS.
		tr.insert(pre);
		fo(i, 0, n - 1) {
			pre = (pre ^ arr[i]); // prefix XOR sum from 0....i
			ans += tr.query(pre, k); // include all subarrays whose XOR sum < K in final ans. ----> O(lgN)
			tr.insert(pre); // Insert XOR sum from 0....i into trie DS.
		}
		cout << ans << nl; // Output final ans.
	}

	//system("pause");
	return 0;
}