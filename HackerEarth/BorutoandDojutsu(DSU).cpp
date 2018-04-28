#include <bits/stdc++.h>
using namespace std;

#define sz(o) ((int)o.size())
#define all(o) o.begin(), o.end()
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define repr(i, a, b) for(int i = (a); i >= (b); i--)

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vi;

const int maxn = 2e5+5;
int n, m, q, pa[maxn], from[maxn], to[maxn];
set<int> s[maxn];
bitset<maxn> bs;
pair<int, int> qe[maxn];

int root(int u){return pa[u]==u ? u : pa[u] = root(pa[u]);}

void merge(int u, int v){
    u = root(u);
    v = root(v);
    if(u==v)return;
    if(u > v) swap(u, v);
    for(auto c : s[v]) s[u].insert(c);
    pa[v] = u;
}

void solve(int testcase) {
    cin >> n >> m >> q;
    rep(i, 1, n){
        int color;
        cin >> color;
        pa[i]=i;
        s[i].insert(color);
    }
    rep(i, 1, m) cin >> from[i] >> to[i];
    rep(i, 1, q){
        cin >> qe[i].first >> qe[i].second;
        if(qe[i].first==1) bs[qe[i].second] = 1;
    }
    rep(i, 1, m) if(!bs[i]) merge(from[i], to[i]);
    vi ans;
    repr(i, q, 1){
        if(qe[i].first==2) ans.push_back(sz(s[root(qe[i].second)]));
        else merge(from[qe[i].second], to[qe[i].second]);
    }
    repr(i, sz(ans)-1, 0) cout << ans[i] << '\n';
}

int main() {
    #ifdef VPAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(2);
    clock_t b = clock();
    int t = 1;
    //cin >> t;
    rep(tt, 1, t) solve(tt);
    clock_t e = clock();
    cerr << (double(e - b) / CLOCKS_PER_SEC) << " sec";
    return 0;
}

