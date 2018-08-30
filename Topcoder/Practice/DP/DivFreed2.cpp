#include <bits/stdc++.h>
using namespace std;

#define sz(o) ((int)o.size())
#define all(o) o.begin(), o.end()
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define repr(i, a, b) for(int i = (a); i >= (b); i--)
#define VPAL 100

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vi;

class DivFreed2{
public:
    int mod = 1e9+7;
    int dp[11][100001], pre[11];
    int count(int n, int k){
        rep(i, 1, k){
            dp[1][i] = 1;
            pre[1] = (dp[1][i] + pre[1])%mod;
        }
        rep(i, 2, n){
            rep(j, 1, k){
                dp[i][j] = pre[i-1];
                for(int w = 2*j; w <= k; w += j) dp[i][j] = (dp[i][j] - dp[i-1][w] + mod)%mod;
                pre[i] = (dp[i][j] + pre[i]) % mod;
            }
        }
        int ans = 0;
        rep(i, 1, k){
            ans += dp[n][i];
            ans %= mod;
        }
        return ans;
    }
};


