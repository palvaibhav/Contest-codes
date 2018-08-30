#include <bits/stdc++.h>
using namespace std;

#define sz(o) ((int)o.size())
#define all(o) o.begin(), o.end()
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define repr(i, a, b) for(int i = (a); i >= (b); i--)

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vi;


void solve() {
    int t;
    cin >> t;
    rep(tt, 1, t){
        ll d;
        cin >> d;
        string s;
        cin >> s;
        int n = sz(s);
        ll x = 1;
        rep(i, 0, n-1){
            if(s[i] == 'C') x <<= 1LL;
            else d-=x;
        }
        if(d >= 0)
            cout << "Case #" << tt << ": " << "0\n";
        else{
            int cnt = 0, ans = 0;
            bool flag = 1;
            repr(i, n-1, 0){
                if(d >= 0){
                    break;
                }
                if(s[i] == 'C'){
                    for(int j = i+1; j < n-cnt && d < 0; j++){
                        d += x;
                        d -= (x >> 1LL);
                        swap(s[j-1], s[j]);
                        ans++;
                    }
                    cnt++;
                    x >>= 1LL;
                }
            }
            if(d >= 0) cout << "Case #" << tt << ": " << ans << "\n";
            else cout << "Case #" << tt << ": " << "IMPOSSIBLE\n";
        }
    }
}

int main() {
    /*#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(10);
    clock_t b = clock();
    solve();
    clock_t e = clock();
    cerr << (double(e - b) / CLOCKS_PER_SEC) << " sec";
    return 0;
}