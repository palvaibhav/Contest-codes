#include <bits/stdc++.h>
using namespace std;

#define sz(o) ((int)o.size())
#define all(o) o.begin(), o.end()
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define repr(i, a, b) for(int i = (a); i >= (b); i--)

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vi;

struct Point{ int x, y; };

//Distance b/w two points
ll dist(Point a, Point b){return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);}

//check func. for square formed by four points
bool ok(Point a, Point b, Point c, Point d){
    Point p[4];
    p[0] = a; p[1] = b; p[2] = c; p[3] = d;
    rep(i, 0, 3){
        rep(j, i+1, 3){
            if(p[i].x == p[j].x and p[i].y == p[j].y) return false;
        }
    }
    int arr[] = {0, 1, 2, 3};
    do{
        ll d1 = dist(p[arr[0]], p[arr[1]]);
        ll d2 = dist(p[arr[1]], p[arr[2]]);
        ll d3 = dist(p[arr[2]], p[arr[3]]);
        ll d4 = dist(p[arr[3]], p[arr[0]]);
        ll d5 = dist(p[arr[0]], p[arr[2]]);
        ll d6 = dist(p[arr[1]], p[arr[3]]);
        if(d1 > 0 and d1 == d2 and d2 == d3 and d3 == d4 and d5 == d6) return true;
    }while(next_permutation(arr, arr+4));
    return false;
}

//Rotate func. for rotating a point about another point 90 deg counter-clockwise
void rotate(Point &a, Point &b){
    a.x -= b.x;
    a.y -= b.y;
    swap(a.x, a.y);
    a.x = -a.x;
    a.x += b.x;
    a.y += b.y;
}

Point p[5][2];

void solve() {
    int n;
    cin >> n;
    while(n--){
        rep(i, 1, 4) cin >> p[i][0].x >> p[i][0].y >> p[i][1].x >> p[i][1].y;
        int ans = 100;
        rep(i, 0, 3){
            rep(j, 0, 3){
                rep(k, 0, 3){
                    rep(l, 0, 3){
                        Point a = p[1][0], b = p[2][0], c = p[3][0], d = p[4][0];
                        rep(w, 1, i) rotate(a, p[1][1]);
                        rep(w, 1, j) rotate(b, p[2][1]);
                        rep(w, 1, k) rotate(c, p[3][1]);
                        rep(w, 1, l) rotate(d, p[4][1]);
                        if(i+j+k+l < ans && ok(a, b, c, d)) ans = i+j+k+l;
                    }
                }
            }
        }
        ans == 100 ? cout << "-1\n" : cout << ans << '\n';
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(8);
    clock_t b = clock();
    solve();
    clock_t e = clock();
    cerr << (double(e - b) / CLOCKS_PER_SEC) << " sec";
    return 0;
}