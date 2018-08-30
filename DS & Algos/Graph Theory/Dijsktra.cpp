
#include <bits/stdc++.h>
using namespace std;

#define sz(o) ((int)o.size())
#define all(o) o.begin(), o.end()
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define repr(i, a, b) for(int i = (a); i >= (b); i--)
#define INF 1000000000
#define MOD 1000000007
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
 * Dijkstra's SSSP Algorithm O((E + V)LogV)
 */

const int N = (int)1e5+1;
vpi adj[N];
vi dist;
int n, m, s;

void dijsktra(int s)
{
    priority_queue<pi> pq;
    dist.assign(n+1, INF);
    dist[s] = 0;
    pq.push({0, -s});

    while(!pq.empty())
    {
        pi front = pq.top();
        pq.pop();
        int u = -front.ss, d = -front.ff;

        if(dist[u] >= d)
        {
            for(auto p : adj[u])
            {
                int v = p.ff;
                int wt = p.ss;
                if(dist[v] > dist[u] + wt)
                {
                    dist[v] = dist[u] + wt;
                    pq.push({-dist[v], -v});
                }
            }
        }
    }
}

void solve(int testcase)
{
    cin >> n >> m >> s;
    rep(i, 1, m)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }
    dijsktra(s);
    rep(i, 1, n) cout << dist[i] << ' ';
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