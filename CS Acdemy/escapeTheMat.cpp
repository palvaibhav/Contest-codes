#include <bits/stdc++.h>
using namespace std;
/*
 Reverse bfs property
 Problem Link :- "https://csacademy.com/contest/archive/task/escape-the-matrix/statement/"
*/

#define sz(o) ((int)o.size())
#define all(o) o.begin(), o.end()
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define repr(i, a, b) for(int i = (a); i >= (b); i--)

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vi;

char g[505][505];
int h, w, ans;
map<char, int> dr = {{'R', 0}, {'D', 1}, {'U', -1}, {'L', 0}};
map<char, int> dc = {{'R', 1}, {'D', 0}, {'U', 0}, {'L', -1}};
bool vis[505][505];

bool check(int x, int y){
    return x < 0 || x == h || y < 0 || y == w;
}

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    while(!q.empty()){
        pair<int, int> u = q.front();
        int xx = u.first, yy = u.second;
        vis[xx][yy] = true;
        q.pop();
        int rx, ry, ux, uy, dx, dy, lx, ly;
        rx = xx + dr['R'];
        ry = yy + dc['R'];
        ux = xx + dr['U'];
        uy = yy + dc['U'];
        dx = xx + dr['D'];
        dy = yy + dc['D'];
        lx = xx + dr['L'];
        ly = yy + dc['L'];
        if(!check(rx, ry) && g[rx][ry] == 'L' && !vis[rx][ry])
            q.push({rx, ry});
        if(!check(ux, uy) && g[ux][uy] == 'D' && !vis[ux][uy])
            q.push({ux, uy});
        if(!check(dx, dy) && g[dx][dy] == 'U' && !vis[dx][dy])
            q.push({dx, dy});
        if(!check(lx, ly) && g[lx][ly] == 'R' && !vis[lx][ly])
            q.push({lx, ly});
    }
}

void solve() {
    cin >> h >> w;
    rep(i, 0, h-1) cin >> g[i];

    rep(i, 0, w-1){
        if(check(0 + dr[g[0][i]], i + dc[g[0][i]]))
            bfs(0, i);
        if(check(h-1 + dr[g[h-1][i]], i + dc[g[h-1][i]]))
            bfs(h-1, i);
    }

    rep(i, 0, h-1){
        if(check(i + dr[g[i][0]], 0 + dc[g[i][0]]))
            bfs(i, 0);
        if(check(i + dr[g[i][w-1]], w-1 + dc[g[i][w-1]]))
            bfs(i, w-1);
    }

    rep(i, 0, h-1) rep(j, 0, w-1) ans += vis[i][j];

    cout << ans;
}

int main() {
    #ifndef ONLINE_JUDGE
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