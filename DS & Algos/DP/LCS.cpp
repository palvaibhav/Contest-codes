#include <bits/stdc++.h>
using namespace std;

#define sz(o) ((int)o.size())
#define all(o) o.begin(), o.end()
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define repr(i, a, b) for(int i = (a); i >= (b); i--)

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vi;


// LCS O(N*M) DP
const int maxn = 1e3+5;
int dp[maxn][maxn];

int LCS(string a, string b){
    int n = sz(a), m = sz(b);

    rep(i, 0, n-1){
        rep(j, 0, m-1){
            if(a[i] == b[j]) dp[i+1][j+1] = 1 + dp[i][j];
            else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
        }
    }

    return dp[n][m];
}

void solve(int testcase) {
    cout << LCS("abcdef", "acbcf");
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

