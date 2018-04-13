#include <bits/stdc++.h>
using namespace std;

#define sz(o) ((int)o.size())
#define all(o) o.begin(), o.end()
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define repr(i, a, b) for(int i = (a); i >= (b); i--)
//#define VPAL 100

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vi;

void solve() {
    int T;
    cin >> T;
    rep(testCase, 1, T){
        int A, I, J;
        cin >> A;
        if(A == 20) {
            while (1) {
                cout << 500 << ' ' << 500 << '\n' << flush;
                cin >> I >> J;
                if (I == J) {
                    if (I == 0) break;
                    else if (I == -1) return;
                }
                cout << 500 << ' ' << 503 << '\n' << flush;
                cin >> I >> J;
                if (I == J) {
                    if (I == 0) break;
                    else if (I == -1) return;
                }
                cout << 500 << ' ' << 506 << '\n' << flush;
                cin >> I >> J;
                if (I == J) {
                    if (I == 0) break;
                    else if (I == -1) return;
                }
            }
        }
        else if(A == 200){
            bool done = false;
            while (!done) {
                rep(i, 0, 22){
                    cout << 500 << ' ' << (500 + i*3) << '\n' << flush;
                    if (I == J) {
                        if (I == 0){
                            done = true;
                            break;
                        }
                        else if (I == -1) return;
                    }
                }
            }
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
    cout << setprecision(10);
    clock_t b = clock();
    solve();
    clock_t e = clock();
    cerr << (double(e - b) / CLOCKS_PER_SEC) << " sec";
    return 0;
}