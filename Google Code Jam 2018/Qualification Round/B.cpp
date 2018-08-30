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
        int n;
        cin >> n;
        vll a, b;
        rep(i, 0, n-1){
            ll x;
            cin >> x;
            if(i&1) b.push_back(x);
            else a.push_back(x);
        }
        sort(all(a));
        sort(all(b));
        int pos = -1, p1 = 0, p2 = 0;
        vll v;
        rep(i, 0, n-1){
            if(i&1) v.push_back(b[p1++]);
            else v.push_back(a[p2++]);
        }
        rep(i, 0, n-2){
            if(v[i] > v[i+1]){
                pos = i;
                break;
            }
        }
        if(pos == -1){
            cout << "Case #" << tt << ": " << "OK\n";
        }
        else{
            cout << "Case #" << tt << ": " << pos << "\n";
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