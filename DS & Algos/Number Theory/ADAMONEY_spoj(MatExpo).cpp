#include <bits/stdc++.h>
using namespace std;

#define sz(o) ((int)o.size())
#define all(o) o.begin(), o.end()
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define repr(i, a, b) for(int i = (a); i >= (b); i--)

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vi;

const ll mod = 1e9+7;

inline ll mul(ll a, ll b) { return (a*b)%mod; }
inline ll add(ll a, ll b) { return (a+b)%mod; }

vector<vll> matMul(vector<vll> &a, vector<vll> &b){
    vector<vll> res(sz(a), vll(sz(b[0])));
    rep(i, 0, sz(a)-1){
        rep(j, 0, sz(b[0])-1){
            rep(k, 0, sz(b)-1){
                res[i][j] = add(res[i][j], mul(a[i][k], b[k][j]));
            }
        }
    }
    return res;
}

vector<vll> matPower(vector<vll> &base, ll p){
    int n = sz(base);
    vector<vll> res(n, vll(n));
    rep(i, 0, n-1) res[i][i] = 1;
    while(p > 0){
        if(p&1) res = matMul(res, base);
        base = matMul(base, base);
        p >>= 1;
    }
    return res;
}

void solve(int testcase) {
    vector<vll> f1(5, vll(1));
    rep(i, 0, 4) cin >> f1[i][0];
    ll n;
    cin >> n;
    if(n < 5){
        cout << f1[n][0] << '\n';
        return;
    }
    vector<vll> T(5, vll(5));
    rep(i, 0, 3) T[i][i+1] = 1;
    T[4][0] = 1;
    T[4][1] = 5;
    T[4][2] = 0;
    T[4][3] = 2;
    T[4][4] = 1;
    T = matPower(T, n-1);
    vector<vll> f = matMul(T, f1);
    cout << f[1][0] << '\n';
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
    cin >> t;
    rep(tt, 1, t)
        solve(tt);
    clock_t e = clock();
    cerr << (double(e - b) / CLOCKS_PER_SEC) << " sec";
    return 0;
}