
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
 * Kosaraju's SCC O(V+E) Algorithm
 */

const int N = (int)1e5+1;
vi adj[N], adj1[N];
bitset<N> mark;
int n, m, sccNum[N], scc;
stack<int> nodes;

void dfs0(int u)
{
    mark[u] = 1;

    for(int v : adj[u])
    {
        if(mark[v]) continue;
        dfs0(v);
    }

    nodes.push(u);
}

void dfs1(int u)
{
    mark[u] = 1;
    sccNum[u] = scc;
    for(int v : adj1[u])
    {
        if(mark[v]) continue;
        dfs1(v);
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
        adj1[v].push_back(u);
    }
    dfs0(1);
    mark.reset();
    rep(i, 1, n)
    {
        if(!mark[i])
        {
            scc++;
            dfs1(i);
        }
    }
    cout << "Count of SCC's : " << scc;
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