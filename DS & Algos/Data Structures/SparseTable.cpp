#include <bits/stdc++.h>
using namespace std;

#define sz(o) ((int)o.size())
#define all(o) o.begin(), o.end()
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define repr(i, a, b) for(int i = (a); i >= (b); i--)

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vi;

class SparseTable{
    static const int MAXN = 1e5+5, LOGMAXN = 20;
    int table[MAXN][LOGMAXN];
    int n, k;

    public:
		// O(NlogN) time and memory preprocessing
        SparseTable(vi &arr){
            n = sz(arr)-1;
            k = 31 - __builtin_clz(n); // highest set bit
            rep(i, 1, n) table[i][0] = arr[i];
            rep(j, 1, k){
                rep(i, 1, n){
                    if(i + (1<<j) - 1 > n) continue;
                    table[i][j] = min(table[i][j-1], table[i+(1<<(j-1))][j-1]);
                }
            }
        }
		
		// O(1) query	
        int minimum(int l, int r){
            int len = r-l+1;
            int k = 31 - __builtin_clz(len); // highest set bit
            return min(table[l][k], table[r-(1<<k)+1][k]);
        }
};

void solve(int testcase) {
    vi arr = {0, 18, 17, 13, 19, 15, 11, 20};

    SparseTable *sp = new SparseTable(arr); // 1-indexing is used here

    cout << sp->minimum(1, 3);
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