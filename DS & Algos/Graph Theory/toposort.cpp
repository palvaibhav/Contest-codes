#include <bits/stdc++.h>
using namespace std;

#define sz(o) ((int)o.size())
#define all(o) o.begin(), o.end()
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define repr(i, a, b) for(int i = (a); i >= (b); i--)

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vi;

const int maxn = 1e5+5;
int n, m, indeg[maxn];
vi adj[maxn], ts1, ts2; // The graph must be a DAG
int color[maxn];
bool cycle = 0;

// toposort using dfs
void dfs(int u){
    if(color[u] == 0){
		color[u] = 1;
		for(int v : adj[u]) dfs(v);
		color[u] = 2;
		ts1.push_back(u);
	}else if(color[u] == 1) cycle = 1;
}

void toposortViadfs(){
    rep(i, 1, n) if(color[i] == 0) dfs(i);
}

// toposort using Kahn's Algo
bool Kahn(){
    int cnt = 0;
    queue<int> q;
    rep(i, 1, n) if(indeg[i] == 0) q.push(i);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        ts2.push_back(u);
        cnt++;
        for(int v : adj[u]){
            if(--indeg[v] == 0) q.push(v);
        }
    }
    return cnt == n; // if false then cycle -->Not a DAG
}

void solve(int testcase) {
    cin >> n >> m;
    rep(i, 1, m){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    toposortViadfs();
	if(cycle) cout << "TopoSort Not possible!\n";
	else{
		for(int v : ts1) cout << v << ' ';
		cout << '\n';
	}
    if(!Kahn()) cout << "TopoSort Not possible!\n";
    else{
        for(int v : ts2) cout << v << ' ';
    }
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