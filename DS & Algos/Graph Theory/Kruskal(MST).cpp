
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
 * Kruskal's Algorithm for MST O(mLogn)
 */

const int N = (int)1e5+1;
int n, m, pa[N];
vector<pair<int, pi>> edges;

int root(int u){return pa[u] == u ? u : pa[u] = root(pa[u]);}

void merge(int u, int v)
{
    u = root(u);
    v = root(v);
    if(u > v) swap(u, v);
    pa[v] = u;
}

bool isSame(int u, int v){return root(u) == root(v);}

int kruskal()
{
    sort(all(edges));
    int k = 0, i = 0, mstCost = 0;
    while(k < n-1)
    {
        auto p = edges[i];
        int u = p.ss.ff, v = p.ss.ss, wt = p.ff;
        if(!isSame(u, v))
        {
            mstCost += wt;
            merge(u, v);
            k++;
        }
        i++;
    }
    return mstCost;
}


void solve(int testcase)
{
    cin >> n >> m;
    rep(i, 1, m)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({wt, {u, v}});
    }
    rep(i, 1, n) pa[i] = i;
    cout << "MST Cost : " << kruskal();
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