
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
 * Prim's Algorithm for MST O(mLogn)
 */

const int N = (int)1e5+1;
int n, m;
vpi adj[N];
bitset<N> taken;
priority_queue<pi> pq;

void process(int u)
{
    taken[u] = 1;
    for(auto p : adj[u])
    {
        if(!taken[p.ff]) pq.push({-p.ss, -p.ff});
    }
}

int prim()
{
    int mstCost = 0;

    process(1);

    while(!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        int u = -p.ss, wt = -p.ff;
        if(!taken[u])
        {
            mstCost += wt;
            process(u);
        }
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
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    cout << "MST Cost : " << prim();
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