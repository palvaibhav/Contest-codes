#include <bits/stdc++.h>
using namespace std;
 
#define sz(o) ((int)o.size())
#define all(o) o.begin(), o.end()
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define repr(i, a, b) for(int i = (a); i >= (b); i--)
#define INF 1000000000000000000LL
#define MOD 1000000009
#define EPS 1e-9
#define PI 3.1415926535
#define ff first
#define ss second
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<pi> vpi;
 
ll T[301][301], F[301][301];
 
ll total(int i, int j){ return (T[i][j] + F[i][j])%MOD; }
 
void solve(int testcase){
    string s, r;
    cin >> s >> r;
    int n = sz(s);
    rep(i, 0, n-1){
        T[i][i] = (s[i] == '1');
        F[i][i] = (s[i] == '0');
    }
 
    rep(gap, 1, n-1){
        rep(i, 0, n-1-gap){
            int j = i+gap;
            rep(k, i, j-1){
                if(r[k] == 'a'){
                    T[i][j] += (T[i][k]*T[k+1][j])%MOD;
                    T[i][j] %= MOD;
                    F[i][j] += ((total(i, k)*total(k+1, j))%MOD - (T[i][k]*T[k+1][j])%MOD + MOD)%MOD;
                    F[i][j] %= MOD;
                }else if(r[k] == 'o'){
                    T[i][j] += ((total(i, k)*total(k+1, j))%MOD - (F[i][k]*F[k+1][j])%MOD + MOD)%MOD;
                    T[i][j] %= MOD;
                    F[i][j] += (F[i][k]*F[k+1][j])%MOD;
                    F[i][j] %= MOD;
                }else{
                    T[i][j] += ((T[i][k]*F[k+1][j])%MOD + (F[i][k]*T[k+1][j])%MOD)%MOD;
                    T[i][j] %= MOD;
                    F[i][j] += ((T[i][k]*T[k+1][j])%MOD + (F[i][k]*F[k+1][j])%MOD)%MOD;
                    F[i][j] %= MOD;
                }
            }
        }
    }
    int q;
    cin >> q;
    while(q--){
        int L, R;
        string res;
        cin >> L >> R >> res;
        L--;
        R--;
        if(res == "true") cout << T[L][R] << '\n';
        else cout << F[L][R] << '\n';
    }
}
 
int main() {
    #ifdef VPAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed << setprecision(20);
    clock_t b = clock();
    int t = 1;
    //cin >> t;
    rep(tt, 1, t) solve(tt);
    clock_t e = clock();
    cerr << (double(e - b) / CLOCKS_PER_SEC) << " sec";
    return 0;
}
