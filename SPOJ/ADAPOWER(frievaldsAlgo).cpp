#include <bits/stdc++.h>
using namespace std;

#define sz(o) ((int)o.size())
#define all(o) o.begin(), o.end()
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define repr(i, a, b) for(int i = (a); i >= (b); i--)
#define INF 1000000000000000000LL
#define MOD 1000000007
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

struct matrix{
    int n, m;
    vector< vi > mat;
    matrix(int n, int m):n(n), m(m){ mat.assign(n, vi(m)); }

    matrix operator * (matrix r){
        matrix res(n, 1);
        rep(i, 0, n-1){
            rep(j, 0, m-1){
                res.mat[i][0] += r.mat[j][0]*mat[i][j];
            }
        }
        return res;
    }

    matrix operator - (matrix other){
        matrix res(n, m);
        rep(i, 0, n-1) rep(j, 0, m-1) res.mat[i][j] = mat[i][j] - other.mat[i][j];
        return res;
    }

    void takeInput(){
        rep(i, 0, n-1) rep(j, 0, m-1) cin >> mat[i][j];
    }

    void show(){
        rep(i, 0, n-1) rep(j, 0, m-1) cout << mat[i][j] << " \n"[j==m-1];
    }

    void fillRandom(){
        rep(i, 0, n-1) rep(j, 0, m-1){
                mat[i][j] = (int)(random()%2LL);
            }
    }

};

bool ok(matrix &A, matrix &B, matrix &C, int k){
    matrix r(A.n, 1);
    rep(i, 1, k){
        r.fillRandom();
        matrix p = (A*(B*r)), q = (C*r);
        rep(i, 0, A.n-1) if(p.mat[i][0]-q.mat[i][0] != 0) return false;
    }
    return true;
}

void solve(int testcase) {
    int n, q;
    cin >> n >> q;
    matrix A(n, n), C(n, n);
    A.takeInput();
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int r1, c1, r2, c2, v;
            cin >> r1 >> c1 >> r2 >> c2 >> v;
            rep(i, r1, r2) rep(j, c1, c2) A.mat[i][j] += v;
        }else{
            C.takeInput();
            cout << (ok(A, A, C, 9) ? "yes\n" : "no\n");
        }
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
