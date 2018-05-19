#include <bits/stdc++.h>
using namespace std;

#define sz(o) ((int)o.size())
#define all(o) o.begin(), o.end()
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define repr(i, a, b) for(int i = (a); i >= (b); i--)

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vi;

const int maxn = 1e5+5, INF=1e9+9;
vi adj[maxn];
int n, m, color[maxn];
bool isBipartite = 1;

//using BFS
void bipartiteGraphCheck1(int s){
    queue<int> q;
    q.push(s);
    rep(i, 1, n) color[i] = INF;
    color[s] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : adj[u]){
            if(color[v] == INF){
                color[v] = 1 - color[u];     // two colors 0 or 1
                q.push(v);
            }else if(color[v] == color[u]){
                isBipartite = 0;
                break;
            }
        }
    }
}

//using dfs
bool bipartiteGraphCheck2(int u, int pa){
    color[u] = 1 - color[pa];
    for(int v : adj[u]){
        if(color[v] == INF){
            if(!bipartiteGraphCheck2(v, u)) return 0;
        }
        else if(color[v] == color[u]) return 0;
    }
    return 1;
}


void solve(int testcase) {
    cin >> n >> m;
    rep(i, 1, m){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    rep(i, 1, n) color[i] = INF;
    rep(i, 1, n) if(color[i] == INF) bipartiteGraphCheck1(i);
    isBipartite ? cout << "YES!\n" : cout << "NO!\n";
}

int main(){
    #ifdef VPAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(10);
    clock_t b = clock();
    int t = 1;
    //cin >> t;
    rep(tt, 1, t) solve(tt);
    clock_t e = clock();
    cerr << (double(e - b) / CLOCKS_PER_SEC) << " sec";
    return 0;
}