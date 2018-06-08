#include <bits/stdc++.h>
using namespace std;

#define sz(o) ((int)o.size())
#define all(o) o.begin(), o.end()
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define repr(i, a, b) for(int i = (a); i >= (b); i--)

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vi;


// Matrix Chain Multiplication O(N^3) DP
const int maxn = 1e2+5, inf = 1e9+7;
int n, row[maxn], col[maxn], cost[maxn][maxn], idx[maxn][maxn];

void pre(){
    rep(i, 1, n){
        rep(j, i+1, n){
            cost[i][j] = inf;
        }
    }
}

void solve(int testcase) {
    cin >> n;
    rep(i, 1, n) cin >> row[i] >> col[i];
    pre();

    rep(j, 2, n){
        for(int x = 1, y = j; y <= n; x++, y++){
            rep(k, x, y-1){
                int temp = cost[x][k] + cost[k+1][y] + row[x]*col[k]*col[y];
                if(temp < cost[x][y]){
                    cost[x][y] = temp;
                    idx[x][y] = k;
                }
            }
        }
    }

    cout << cost[1][n];
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

