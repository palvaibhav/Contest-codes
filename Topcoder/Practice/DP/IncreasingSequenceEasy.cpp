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

class IncreasingSequencesEasy{
public:
    int mod = 998244353;
    int dp[305][10005], pre[305][10005];

    int count(vi L, vi R){
       int n = sz(L), mx = 0;
        rep(i, 0, n-1) mx = max(mx, R[i]);
        rep(i, L[0], R[0]) dp[0][i] = 1;
        rep(i, 1, mx+1) pre[0][i] = (dp[0][i] + pre[0][i-1])%mod;

        rep(i, 1, n-1){
            rep(j, L[i], R[i]) dp[i][j] = pre[i-1][j-1];
            rep(j, 1, mx+1) pre[i][j] = (dp[i][j] + pre[i][j-1])%mod;
        }
        int ans = 0;
        rep(i, L[n-1], R[n-1]){
            ans += dp[n-1][i];
            ans %= mod;
        }
        return ans;
    }
};