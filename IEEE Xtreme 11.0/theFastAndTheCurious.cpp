/* -------------------------------------------------

Author :- Vaibhav Pal
College :- Northern India Engineering College, New Delhi
Coding Handle :- underdog_eagle
Title :-

----------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define INF 1000000000
#define nl '\n'
#define sp ' '
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define fo(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)

const int N = (int)(1e5 + 5), UNVISITED = 0;
int n, m;
vi adjList[N];
vi dfs_num;
vi dfs_low;
vi dfs_parent;
int dfs_counter;

void dfs(int u){
    dfs_low[u] = dfs_num[u] = dfs_counter++;

    for(int j = 0; j < adjList[u].size(); j++){
        int v = adjList[u][j];
        if(dfs_num[v] == UNVISITED){
            dfs_parent[v] = u;
            dfs(v);
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if(v != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
}


int main()
{
    FAST_IO
    cin >> n >> m;
    fo(i, 1, m){
        int a, b;
        cin >> a >> b;
        adjList[a].pb(b);
        adjList[b].pb(a);
    }
    dfs_num.assign(n + 5, UNVISITED);
    dfs_low.assign(n + 5, 0);
    dfs_parent.assign(n + 5, 0);
    dfs_counter = 1;
    //dfs(1);
    for(int i = 1; i <= n; i++){
        if(dfs_num[i] == UNVISITED)
            dfs(i);
    }

    //for(int i = 1; i <= n; i++) cout << dfs_low[i] << sp;
    int mx = 0;
    for(int i = 1; i <= n; i++) mx = max(mx, dfs_low[i]);
    vi arr[mx + 1];
    for(int i = 1; i <= n; i++) arr[dfs_low[i]].pb(i);

    for(int i = 1; i <= mx; i++){
        if(arr[i].size() == 1){
            for(int j = 0; j < arr[i].size(); j++)
                cout << arr[i][j] << nl;
        }
    }

    //cout << ans;

    return 0;
}

/*

8 9
1 3
3 2
3 4
2 4
2 5
5 4
6 8
6 7
7 8

*/
