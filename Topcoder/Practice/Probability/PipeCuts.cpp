#include <bits/stdc++.h>
using namespace std;

#define sz(o) ((int)o.size())
#define all(o) o.begin(), o.end()
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define repr(i, a, b) for(int i = (a); i >= (b); i--)
#define INF 1000000000000000007LL
#define MOD 1000000000
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


class PipeCuts{
public:
    double probability(vi weldLocations, int L){
        int n = sz(weldLocations);
        int total = n*(n-1)/2;
        int odds = 0;
        rep(i, 0, n-1){
            rep(j, i+1, n-1){
                int x = weldLocations[i];
                int y = weldLocations[j];
                if(x>y) swap(x, y);
                if(x > L) odds++;
                else if(y-x > L) odds++;
                else if(100-y > L) odds++;
            }
        }
        return (double)odds/total;
    }
};

/*

void solve(int testcase){

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
*/
