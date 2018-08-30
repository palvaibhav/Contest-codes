/* -------------------------------------------------

Author :- Vaibhav Pal
College :- Norhtern India Engineering College, New Delhi
Coding Handle :- underdog_eagle
Title :- SCC with Tarjan's Algorithm

----------------------------------------------------*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define INF 1000000000

#define UNVISITED 0

const int N = 1e5 + 5;
vi AdjList[N];
vi dfs_num, dfs_low, S, visited;
int dfsNumberCounter, numSCC;

void tarjanSCC(int u){
    dfs_low[u] = dfs_num[u] = ++dfsNumberCounter;
    visited[u] = 1;
    S.push_back(u);

    for(int i = 0; i < AdjList[u].size(); i++){
        int v = AdjList[u][i];
        if(dfs_num[v] == UNVISITED)
            tarjanSCC(v);
        if(visited[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if(dfs_num[u] == dfs_low[u]){
        cout << "SCC " << ++numSCC << ":";
        while(1){
            int v = S.back();
            S.pop_back();
            visited[v] = 0;
            cout << " " << v;
            if(u == v)
                break;
        }
        cout << "\n";
    }
}

int main()
{
    FAST_IO

    int V, E;
    cin >> V >> E;

    dfs_num.assign(V + 1, UNVISITED);
    dfs_low.assign(V + 1, 0);
    visited.assign(V + 1, 0);
    dfsNumberCounter = numSCC = 0;

    for(int i = 1; i <= E; i++){
        int u, v;
        cin >> u >> v;
        AdjList[u].push_back(v);
    }

    tarjanSCC(1);

    return 0;
}
