#include <bits/stdc++.h>
using namespace std;

#define sz(o) ((int)o.size())
#define all(o) o.begin(), o.end()
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define repr(i, a, b) for(int i = (a); i >= (b); i--)
#define vpal 100

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vi;

int r, c, h, v, tot_din, tot_at, d;
char g[105][105];
int pre[105][105];

int sum(int x1, int y1, int x2, int y2){
    return pre[x2][y2] - pre[x2][y1-1] - pre[x1-1][y2] + pre[x1-1][y1-1];
}

void solve(int testcase) {
    cin >> r >> c >> h >> v;
    rep(i, 1, r) cin >> (g[i] + 1);
    rep(i, 1, r){
        rep(j, 1, c){
            pre[i][j] = (g[i][j] == '@') + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
        }
    }
    tot_din = (h+1)*(v+1);
    tot_at = sum(1, 1, r, c);
    bool flag = true;
    if(tot_at % (h+1) != 0 || tot_at % (v+1) != 0 || tot_at % tot_din != 0)
        flag = false;
    else if(tot_at != 0){
        int d1 = tot_at/(h+1);
        int d2 = tot_at/(v+1);
        int prev = 0;

        vi row_cuts, col_cuts;

        rep(i, 1, r){
            int slice_sum = sum(1, 1, i, c);
            if(prev != 0) slice_sum -= sum(1, 1, prev, c);
            if(slice_sum == d1){
                row_cuts.push_back(i);
                prev = i;
            }
        }
        prev = 0;
        rep(i, 1, c){
            int slice_sum = sum(1, 1, r, i);
            if(prev != 0) slice_sum -= sum(1, 1, r, prev);
            if(slice_sum == d2){
                col_cuts.push_back(i);
                prev = i;
            }
        }
        if(sz(row_cuts) != h+1 || sz(col_cuts) != v+1)
            flag = false;
        else{
            int d = tot_at / tot_din;
            rep(i, 0, sz(row_cuts) - 1) {
                rep(j, 0, sz(col_cuts) - 1){
                    int x1 = ((i==0) ? 0 : row_cuts[i-1]) + 1, y1 = ((j==0) ? 0 : col_cuts[j-1]) + 1;
                    int x2 = row_cuts[i], y2 = col_cuts[j];
                    if(sum(x1, y1, x2, y2) != d){
                        flag = false;
                        break;
                    }
                 }
                if(!flag) break;
            }
        }
    }
    cout << "Case #" << testcase << ": " << (flag ? "POSSIBLE\n" : "IMPOSSIBLE\n");
}

int main() {
    #ifdef vpal
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
    rep(tt, 1, t) solve(tt);
    clock_t e = clock();
    cerr << (double(e - b) / CLOCKS_PER_SEC) << " sec";
    return 0;
}