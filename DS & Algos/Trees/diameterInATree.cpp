#include <bits/stdc++.h>
using namespace std;

#define sz(o) ((int)o.size())
#define all(o) o.begin(), o.end()
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define repr(i, a, b) for(int i = (a); i >= (b); i--)

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vi;

const int maxn = 10010;
vi adj[maxn];
vector<bool> vis;
int n;

// O(n) Time and O(1) space
int findDiameterUsingDFS(int u, int pa, int& dia) {
	int largestChildDepth = -1, secondLargestChildDepth = -1, maxDepth = -1;

	for (int v : adj[u]) {
		if (v == pa) continue;
		int depth = findDiameterUsingDFS(v, u, dia);
		maxDepth = max(maxDepth, depth);
		if (depth > largestChildDepth) {
			secondLargestChildDepth = largestChildDepth;
			largestChildDepth = depth;
		}
		else if (depth > secondLargestChildDepth)
			secondLargestChildDepth = depth;
	}

	dia = max(dia, largestChildDepth + secondLargestChildDepth + 2);
	return 1 + maxDepth;
}

pair<int, int> BFS(int start) {
	vis.assign(n + 1, 0);
	int maxDis = -1, node = 0;
	queue<pair<int, int> > q;
	
	q.push({ start, 0 });
	while (!q.empty()) {
		pair<int, int> u = q.front();
		vis[u.first] = 1;
		if (maxDis < u.second) {
			maxDis = u.second;
			node = u.first;
		}
		for (int v : adj[u.first]) {
			if (vis[v]) continue;
			q.push({v, u.second + 1});
		}
		q.pop();
	}

	return {maxDis, node};
}

// O(n) Time and O(n) for boolean array
int findDiameterUsingBFS() {
	pair<int, int> f = BFS(1);
	pair<int, int> s = BFS(f.second);
	return s.first;
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif 

	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	//int dia = 0;
	//findDiameterUsingDFS(1, 0, dia);
	int dia = findDiameterUsingBFS();

	cout << dia;

	return 0;
}