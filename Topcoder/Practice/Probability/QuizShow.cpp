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

class QuizShow{
public:
    int wager(vi scores, int wager1, int wager2){
        int best = 0, bestodds = 0;
        rep(wage, 0, scores[0]){
            int odds = 0;
            for(int i = -1; i <= 1; i += 2) for(int j = -1; j <= 1; j += 2) for(int k = -1; k <= 1; k += 2){
                int x = scores[0] + i*wage;
                int y = scores[1] + j*wager1;
                int z = scores[2] + k*wager2;
                if(x > y && x > z) odds++;
            }
            if(odds > bestodds){
                best = wage;
                bestodds = odds;
            }
        }
        return best;
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
    cin >> t;
    rep(tt, 1, t) solve(tt);
    clock_t e = clock();
    cerr << (double(e - b) / CLOCKS_PER_SEC) << " sec";
    return 0;
}
 */
