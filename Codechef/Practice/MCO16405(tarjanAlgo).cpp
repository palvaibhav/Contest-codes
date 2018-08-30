/* -------------------------------------------------

Author :- Vaibhav Pal
College :- Norhtern India Engineering College, New Delhi
Coding Handle :- underdog_eagle
Title :- Codechef Problem ---> MCO16405

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
int n, m, dfsNumberCounter, numSCC;
vector<ll> PeopleCnt, PeopleCnt2, dp;
vi dfs_num, dfs_low, visited, S, whichSCC;
vi AdjList1[N];
vi AdjList2[2*N];

void tarjanSCC(int u){
    dfs_low[u] = dfs_num[u] = ++dfsNumberCounter;
    visited[u] = 1;
    S.push_back(u);

    for(int i = 0; i < AdjList1[u].size(); i++){
        int v = AdjList1[u][i];
        if(dfs_num[v] == UNVISITED)
            tarjanSCC(v);
        if(visited[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if(dfs_num[u] == dfs_low[u]){
        ++numSCC;
        while(1){
            int v = S.back();
            S.pop_back();
            visited[v] = 0;
            whichSCC[v] = numSCC;
            if(u == v)
                break;
        }
    }
}

void tarjanSCCUtil(){
    for(int i = 1; i <= n; i++){
        if(!dfs_num[i])
            tarjanSCC(i);
    }
}

void dfs(int u){
    visited[u] = 1;
    PeopleCnt2[whichSCC[u]] += PeopleCnt[u];

    for(int i = 0; i < AdjList1[u].size(); i++){
        int v = AdjList1[u][i];
        if(!visited[v])
            dfs(v);
        if(whichSCC[u] != whichSCC[v])
            AdjList2[whichSCC[u]].push_back(whichSCC[v]);
    }

}

void dfsUtil(){
    for(int i = 1; i <= n; i++){
        if(!visited[i])
            dfs(i);
    }
}

void dfs2(int u){
    visited[u] = 1;
    dp[u] = PeopleCnt2[u];

    ll mx = 0;
    for(int i = 0; i < AdjList2[u].size(); i++){
        int v = AdjList2[u][i];
        if(!visited[v])
            dfs(v);
        mx = max(mx, dp[v]);
    }

    dp[u] += mx;
}

void dfs2Util(){
    for(int i = 1; i <= numSCC; i++){
        if(!visited[i])
            dfs2(i);
    }
}

int main()
{
    FAST_IO

    cin >> n >> m;

    PeopleCnt.assign(n + 1, 0);
    dfs_num.assign(n + 1, 0);
    dfs_low.assign(n + 1, 0);
    visited.assign(n + 1, 0);
    whichSCC.assign(n + 1, 0);
    dfsNumberCounter = numSCC = 0;

    for(int i = 1; i <= n; i++)
        cin >> PeopleCnt[i];

    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        AdjList1[u].push_back(v);
    }

    tarjanSCCUtil();

    /*for(int i = 1; i <= n; i++)
        cout << whichSCC[i] << " ";
        cout << "\n";*/

    PeopleCnt2.assign(numSCC + 1, 0);
    visited.assign(n + 1, 0);

    dfsUtil();

    /*for(int i = 1; i <= numSCC; i++){
        cout << i << " : ";
        for(int j = 0; j < AdjList2[i].size(); i++)
            cout << AdjList2[i][j] << " ";
        cout << "\n";
    }*/

    dp.assign(numSCC + 1, 0);
    visited.assign(n + 1, 0);

    dfs2Util();

    for(int i = 1; i <= n; i++){
        cout << dp[whichSCC[i]] << " ";
    }

    return 0;
}

/*

4 5
1 2 3 4
1 2
1 3
2 3
3 4
4 2
10 9 9 9

*/
