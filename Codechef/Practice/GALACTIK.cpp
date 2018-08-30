/* -------------------------------------------------

Author :- Vaibhav Pal
College :- Northern India Engineering College, New Delhi
Coding Handle :- underdog_eagle
Title :- codechef problem ---> GALACTIK(Disjoint sets or CC's)

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

const int N = (int)(1e5 + 5);
int n, m;
vi adjList[N], minCost;
bool vis[N];
int c[N];

int dfs(int u){
    vis[u] = true;
    int cost = c[u];
    for(int i = 0; i < adjList[u].size(); i++){
        int v = adjList[u][i];
        if(!vis[v]){
            int temp = dfs(v);
            if(cost < 0 && temp >= 0)
                cost = temp;
            else if(cost >= 0 && temp >= 0)
                cost = min(cost, temp);
        }
    }
    return cost;
}

int main()
{
    FAST_IO
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
    for(int i = 1; i <= n; i++){
        cin >> c[i];
        vis[i] = false;
    }

    for(int i = 1; i <= n; i++)
        if(!vis[i]) minCost.pb(dfs(i));

    if(minCost.size() > 1){
        int mn = minCost[0], tot_sum = 0;
        for(int i = 0; i < minCost.size(); i++)
            mn = min(mn, minCost[i]), tot_sum += minCost[i];

        mn < 0 ? cout << "-1" : cout << ((minCost.size() - 1)*mn + tot_sum - mn);
    }
    else
        cout << "0";

    return 0;
}
