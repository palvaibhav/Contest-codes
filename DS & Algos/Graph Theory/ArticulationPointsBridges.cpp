
#include <bits/stdc++.h>
using namespace std;

#define sz(o) ((int)o.size())
#define all(o) o.begin(), o.end()
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define repr(i, a, b) for(int i = (a); i >= (b); i--)
#define INF 1000000000000LL
#define MOD 1000000007LL
#define ff first
#define ss second
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<pi> vpi;

/*
 * Articulation points and bridges O(V+E) Algorithm
 */

const int N = (int)1e5+1;
vi adj[N];
bitset<N> isArticulationVertex;
int n, m, dfs_num[N], dfs_low[N], dfs_parent[N], timer, dfsRoot, rootChildren;

void dfs(int u)
{
    dfs_num[u] = dfs_low[u] = ++timer;

    for(int v : adj[u])
    {
        if(dfs_num[v] == 0)
        {
            dfs_parent[v] = u;
            if(u == dfsRoot) rootChildren++;
            dfs(v);

            if(dfs_low[v] >= dfs_num[u]) isArticulationVertex[u] = true;
            if(dfs_low[v] > dfs_num[u])
            {
                cout << "Articulation Bridge : " << u << ' ' << v << '\n';
            }

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else
        {
            if(v != dfs_parent[u])
            {
                dfs_low[u] = min(dfs_low[u], dfs_num[v]);
            }
        }
    }

}

void solve(int testcase)
{
    cin >> n >> m;
    rep(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfsRoot = 1;
    dfs(1);
    isArticulationVertex[dfsRoot] = (rootChildren > 1);
    cout << "Articulation vertices : ";
    rep(i, 1, n)
    {
        if(isArticulationVertex[i]) cout << i << ' ';
    }
}

signed main()
{
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