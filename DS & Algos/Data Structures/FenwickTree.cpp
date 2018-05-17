#include <bits/stdc++.h>
using namespace std;

#define sz(o) ((int)o.size())
#define all(o) o.begin(), o.end()
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define repr(i, a, b) for(int i = (a); i >= (b); i--)

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vi;

const int maxn = 1e5+5;
int bit[maxn], n;

void update(int idx, int val){
    for(; idx <= n; idx += (idx & -idx)) bit[idx] += val;
}

int sum(int idx){
    int res = 0;
    for(; idx > 0; idx -= (idx & -idx)) res += bit[idx];
    return res;
}

int query(int l, int r){
    return sum(r) - sum(l-1);
}

void solve(int testcase) {
    vi v = {0, 1, 2, 3, 4, 5, 6};
    n = 6;
    rep(i, 1, n) update(i, v[i]);
    cout << query(3, 6);
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