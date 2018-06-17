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
 * Optimal Binary Search Tree DP O(N^3)
 */

const int N = 1005;
int n, keys[N], freq[N], root[N][N];
int pre[N];

namespace recursive{
    int dp[N][N];

    int sum(int i, int j){return pre[j]-pre[i-1];}

    int optCost(int i, int j){
        if(j < i || i > j) return 0;
        if(i == j) return freq[i];
        if(dp[i][j] != -1) return dp[i][j];
        int cost = sum(i, j), mn = INF;
        rep(r, i, j){
            int x = optCost(i, r-1) + optCost(r+1, j);
            if(x < mn){
                mn = x;
                root[i][j] = r;
            }
        }
        cost += mn;
        return dp[i][j] = cost;
    }
}

namespace iterative{
    int dp[N][N];

    int sum(int i, int j){return pre[j]-pre[i-1];}

    int optCost(int i, int j){
        rep(i, 1, n) dp[i][i] = freq[i];

        for(int L = 2; L <= n; L++){
            for(int i = 1, j = i+L-1; j <= n; i++, j++){
                dp[i][j] = sum(i, j);
                int mn = INF;
                for(int r = i; r <= j; r++){
                    int x = dp[i][r-1] + dp[r+1][j];
                    if(x < mn){
                        mn = x;
                        root[i][j] = r;
                    }
                }
                dp[i][j] += mn;
            }
        }

        return dp[1][n];
    }
}


void solve(int testcase) {
    cin >> n;
    rep(i, 1, n) cin >> keys[i];
    rep(i, 1, n) cin >> freq[i];
    rep(i, 1, n) pre[i] = pre[i-1] + freq[i];
    memset(recursive::dp, -1, sizeof(recursive::dp));
    cout << recursive::optCost(1, n) << '\n';
    cout << iterative::optCost(1, n) << '\n';
}

/*
 
4
10 20 30 40
4 2 6 3
 
answer = 26
 
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