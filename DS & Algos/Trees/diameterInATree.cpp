#include <bits/stdc++.h>
using namespace std;

const int maxn = 10010;
vector<int> AdjList[maxn];
vector<bool> vis;
int n;

// O(n) Time and O(1) space
int findDiameterUsingDFS(int u, int pa, int& dia) {
	int largestChildDepth = -1, secondLargestChildDepth = -1, maxDepth = -1;

	for (int i = 0; i < AdjList[u].size(); i++) {
		int v = AdjList[u][i];
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
		for (int i = 0; i < AdjList[u.first].size(); i++) {
			int v = AdjList[u.first][i];
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
		AdjList[u].push_back(v);
		AdjList[v].push_back(u);
	}

	//int dia = 0;
	//findDiameterUsingDFS(1, 0, dia);
	int dia = findDiameterUsingBFS();

	cout << dia;

	return 0;
}