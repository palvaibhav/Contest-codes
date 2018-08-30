
#include <bits/stdc++.h>
using namespace std;

#define sz(o) ((int)o.size())
#define all(o) o.begin(), o.end()
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define repr(i, a, b) for(int i = (a); i >= (b); i--)
#define INF 1000000007
#define MOD 1000000007
#define ff first
#define ss second
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<pi> vpi;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

class TeleportationMaze
{
public:
    pi cell[55][55][4];
    int dist[55][55], r, c;

    void go(vector<string> &a)
    {
        rep(i, 0, r) rep(j, 0, c) dist[i][j] = INF;
        memset(cell, -1, sizeof(cell));
        rep(i, 0, r-1) rep(j, 0, c-1)
            {
                repr(k, i-1, 0)
                {
                    if(a[k][j] == '.')
                    {
                        cell[i][j][0] = {k, j};
                        break;
                    }
                }

                rep(k, j+1, c-1)
                {
                    if(a[i][k] == '.')
                    {
                        cell[i][j][1] = {i, k};
                        break;
                    }
                }

                rep(k, i+1, r-1)
                {
                    if(a[k][j] == '.')
                    {
                        cell[i][j][2] = {k, j};
                        break;
                    }
                }

                repr(k, j-1, 0)
                {
                    if(a[i][k] == '.')
                    {
                        cell[i][j][3] = {i, k};
                        break;
                    }
                }

            }
    }

    bool inside(int x, int y){return x >= 0 && x < r && y >= 0 && y < c;}

    void doThis(vector<string> &a, priority_queue<pair<int, pi>> &q, int x, int y, int d)
    {
        rep(i, 0, 3)
        {
            int xx = x + dr[i];
            int yy = y + dc[i];

            if(inside(xx, yy))
            {
                if(a[xx][yy] == '.')
                {
                    if(dist[xx][yy] > d+1)
                    {
                        q.push({-(d+1), {xx, yy}});
                        dist[xx][yy] = d+1;
                    }
                }
            }
        }

        rep(i, 0, 3)
        {
            pi there = cell[x][y][i];
            int xx = there.ff;
            int yy = there.ss;
            if(inside(xx, yy))
            {
                if(dist[xx][yy] > d+2)
                {
                    dist[xx][yy] = d+2;
                    q.push({-(d+2), {xx, yy}});
                }
            }
        }
    }

    int pathLength(vector<string> a, int r1, int c1, int r2, int c2)
    {
         r = sz(a);
         c = sz(a[0]);
        go(a);

        priority_queue<pair<int, pi>> q;
        q.push({0, {r1, c1}});
        dist[r1][c1] = 0;
        int ans = -1;
        while(!q.empty())
        {
            auto p = q.top();
            q.pop();
            int x = p.ss.ff, y = p.ss.ss, d = -p.ff;
            if(d > dist[x][y]) continue;
            //cerr << x << ' ' << y << '\n';
            if(x == r2 && y == c2)
            {
                ans = d;
                break;
            }

            doThis(a, q, x, y, d);
        }

        return ans;
    }
};




void solve(int testcase)
{
    TeleportationMaze *obj = new TeleportationMaze();
    cerr << obj->pathLength(	{"#.######.#", "#.########", "#####.###.", "##.####.##", "######..#.", "#####.#.##", "...#######", "#.#.#.###.", "###..###..", "####..####", "##########", "###..#.###", "#.##..###.", "###.######", "####.###..", "#.####..##", "#..###..##", "#########.", "###.######", "##.#######", "##########", "##########", "##########", "#.#.#.####", "######.###", "###.#.####", ".#########", "###..#####", ".#####.#.#", "######.###", "####..####", ".####.###.", "#.#######.", "##########", "##########", "##.##.##.#", ".##..#####", "#..##.##.#", "#####..#.#", "###.##..##", ".#########", "##########", "####.#.###", "########.#", ".#########", "##########", ".###.#####", ".#######..", ".#######.#", "#.########"}, 42, 6, 18, 3);
    cerr << '\n';

}

signed main()
{
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

