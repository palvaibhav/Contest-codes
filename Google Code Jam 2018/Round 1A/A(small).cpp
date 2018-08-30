#include <bits/stdc++.h>
using namespace std;

#define sz(o) ((int)o.size())
#define all(o) o.begin(), o.end()
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define repr(i, a, b) for(int i = (a); i >= (b); i--)
//#define vpal 100

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vi;

int r, c, h, v;
char g[105][105];

int sum(int sx, int sy, int ex, int ey){
    int res = 0;
    rep(i, sx, ex) rep(j, sy, ey) res += g[i][j] == '@';
    return res;
}

void solve(int testcase) {
    cin >> r >> c >> h >> v;
    rep(i, 1, r) cin >> (g[i] + 1);
    bool flag = false;
    rep(i, 1, r){
        rep(j, 1, c){
            int s1 = sum(1, 1, i-1, j-1);
            int s2 = sum(1, j, i-1, c);
            int s3 = sum(i, 1, r, j-1);
            int s4 = sum(i, j, r, c);
            if(s1 == s2 and s2 == s3 and s3 == s4){
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    cout << "Case #" << testcase << ": " << (flag ? "POSSIBLE\n" : "IMPOSSIBLE\n");
}

int main() {
    #ifdef vpal
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(10);
    clock_t b = clock();
    int t = 1;
    cin >> t;
    rep(tt, 1, t) solve(tt);
    clock_t e = clock();
    cerr << (double(e - b) / CLOCKS_PER_SEC) << " sec";
    return 0;
}
