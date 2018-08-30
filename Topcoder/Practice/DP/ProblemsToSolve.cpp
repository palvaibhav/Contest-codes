#include <bits/stdc++.h>
using namespace std;

#define sz(o) ((int)o.size())
#define all(o) o.begin(), o.end()
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define repr(i, a, b) for(int i = (a); i >= (b); i--)
#define INF 1000000000
#define MOD 1000000007LL
#define ff first
#define ss second
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<pi> vpi;


class ProblemsToSolve
{
public:

    bool out(int x, int l, int r){ return x < l || x > r; }

    int cal(int x){ return x/2; }

    bool good(vi &p, int l, int r, int mn, int mx)
    {
        rep(i, l, r-1)
        {
            if(out(p[i], mn, mx))
            {
                return 0;
            }
        }
        return 1;
    }

    int minNumber(vi p, int k)
    {
        int n = sz(p);

        int res = n;

        rep(i, 0, n-1)
        {
            rep(j, i+1, n-1)
            {
                int mn = min(p[i], p[j]), mx = max(p[i], p[j]), diff = abs(mn - mx);
                if(diff >= k)
                {
                    if(out(p[0], mn, mx)) continue;
                    if(!good(p, 0, i-1, mn, mx) || !good(p, i+1, j-1, mn, mx)) continue;
                    int tmp = 2 + (i != 0) + cal(i-1) + cal(j-i-1);
                    res = min(res, tmp);
                }
            }
        }

        return res;
    }

};