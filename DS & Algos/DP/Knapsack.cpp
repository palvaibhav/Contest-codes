#include <bits/stdc++.h>
using namespace std;

#define sz(o) ((int)o.size())
#define all(o) o.begin(), o.end()
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define repr(i, a, b) for(int i = (a); i >= (b); i--)

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vi;


// 0/1 Knapsack Problem O(N^2)
const int maxn = 1e3+5;
int n, mxwt, dp[maxn][maxn], wt[maxn], val[maxn];

void solve(int testcase) {
    cin >> n >> mxwt;
    rep(i, 1, n) cin >> wt[i] >> val[i];
    rep(i, 1, n){
        rep(j, 1, mxwt){
            if(wt[i] <= j) dp[i][j] = max(val[i] + dp[i-1][j - wt[i]], dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][mxwt];
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

