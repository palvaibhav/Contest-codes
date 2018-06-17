#include <bits/stdc++.h>
using namespace std;

#define sz(o) ((int)o.size())
#define all(o) o.begin(), o.end()
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define repr(i, a, b) for(int i = (a); i >= (b); i--)
#define INF 1000000000

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vi;

/*
 * Subset Sum DP O(N*SUM)
 */

const int N = 1005;
int n, a[N], sum;

namespace recursive{
    int dp[N][N];

    bool isSubset(int n, int sum){
        if(n==0) return sum == 0;
        if(sum == 0) return true;
        if(sum < 0) return false;
        if(dp[n][sum] != -1) return dp[n][sum];
        return (bool)(dp[n][sum] = isSubset(n-1, sum) or isSubset(n-1, sum-a[n]));
    }

}

namespace iterative{
    bool dp[N][N];

    bool isSubset(int n, int sum){
        rep(i, 0, n) dp[i][0] = true;
        rep(i, 1, n){
            rep(j, 1, sum){
                if(a[i] <= j) dp[i][j] = dp[i-1][j] or dp[i-1][j-a[i]];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
    }

    vi backtrace(){
        vi subset;
        int SUM = sum, N = n;
        if(!dp[n][sum]) return subset;
        while(SUM > 0){
            if(dp[N-1][SUM]){
                //ignore Nth
                N--;
            }else{
                //include Nth
                subset.push_back(a[N]);
                SUM = SUM - a[N];
                N--;
            }
        }
        return subset;
    }

    vi getSubset(){return backtrace();}

}


void solve(int testcase) {
    cin >> n >> sum;
    rep(i, 1, n) cin >> a[i];
    memset(recursive::dp, -1, sizeof(recursive::dp));
    cout << recursive::isSubset(n, sum) << '\n';
    cout << iterative::isSubset(n, sum) << '\n';
    vi subset = iterative::getSubset();
    rep(i, 0, sz(subset)-1) cout << subset[i] << ' ';
}

/*

5 11
2 3 7 8 10
 
answer - 1
 
5 14
2 3 7 8 10

answer  - 0  
  
 */


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