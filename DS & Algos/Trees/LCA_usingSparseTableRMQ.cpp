#include <bits/stdc++.h>
using namespace std;

#define sz(o) ((int)o.size())
#define all(o) o.begin(), o.end()
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define repr(i, a, b) for(int i = (a); i >= (b); i--)

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vi;

const int MAXN =1e5+5;
vi adj[MAXN];

class SparseTable{
    static const int MAXN = 1e5+5, LOGMAXN = 20;
    int table[MAXN][LOGMAXN], itable[MAXN][LOGMAXN], idx[2*MAXN], L[2*MAXN], low[MAXN], tim = 1;
    int n, k;

public:
    // O(NlogN) time and memory preprocessing
    SparseTable(int len){
        n = len;
        k = 31 - __builtin_clz(n); // highest set bit
        dfs(1, 0, 0);
        rep(i, 1, n) table[i][0] = L[i], itable[i][0] = i;
        rep(j, 1, k){
            rep(i, 1, n){
                if(i + (1<<j) - 1 > n) continue;
                if(table[i][j-1] < table[i+(1<<(j-1))][j-1]){
                    table[i][j] = table[i][j-1];
                    itable[i][j] = itable[i][j-1];
                }else{
                    table[i][j] = table[i+(1<<(j-1))][j-1];
                    itable[i][j] = itable[i+(1<<(j-1))][j-1];
                }
            }
        }
    }

    // dfs for precomputing 
    void dfs(int u, int par, int depth){
        low[u] = tim;
        L[tim] = depth;
        idx[tim++] = u;
        for(int v : adj[u]){
            if(v == par) continue;
            dfs(v, u, depth+1);
            idx[tim] = u; // Back to the current node so register it in the idx array
            L[tim++] = depth;
        }
    }

    // O(1) query
    int RMQ(int l, int r){
        int len = r-l+1;
        int k = 31 - __builtin_clz(len); // highest set bit
        if(table[l][k] < table[r-(1<<k)+1][k]) return itable[l][k];
        else return itable[r-(1<<k)+1][k];
    }

    int LCA(int u, int v){
        if(low[u] > low[v]) swap(u, v);
        return idx[RMQ(low[u], low[v])];
    }
};

void solve(int testcase) {
    int n;
    cin >> n;
    rep(i, 1, n-1){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    SparseTable *sp = new SparseTable(2*n-1);
    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        cout <<  sp->LCA(a, b) << '\n';
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