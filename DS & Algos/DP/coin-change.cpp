#include <bits/stdc++.h>
using namespace std;

#define sz(o) ((int)o.size())
#define all(o) o.begin(), o.end()
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define repr(i, a, b) for(int i = (a); i >= (b); i--)
#define INF 10000000

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vi;


// Coin Change DP O(N*SUM)
const int N = 1e3+1;
int n, coin[N], sum;

namespace recursive{
    int dp[N];

    int minCoins(int n, int sum){
        if(sum == 0) return 0;
        int res = INF;
        rep(i, 1, n){
            if(sum >= coin[i]) res = min(res, 1 + minCoins(n, sum-coin[i]));

        }
        return dp[sum] = res;
    }
}

namespace iterative{
    int dp[N];

    int minCoins(){
        rep(i, 1, sum) dp[i] = INF;

        rep(i, 1, sum){
            rep(j, 1, n){
                if(j >= coin[i]) dp[i] = min(dp[i], 1 + dp[i-coin[j]]);
            }
        }

        return dp[sum];
    }
}

void solve(int testcase) {
    cin >> n >> sum;
    rep(i, 1, n) cin >> coin[i];
    memset(recursive::dp, -1, sizeof(recursive::dp));
    cout << recursive::minCoins(n, sum) << '\n';
    cout << iterative::minCoins() << '\n';
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
