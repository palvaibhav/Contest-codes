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


class RGBStreet
{
public:

    int cost[21][3];
    int dp[21][4];

    int f(int n, int c)
    {
        if(n == -1) return 0;
        if(dp[n][c] != -1) return dp[n][c];

        int res = INF;

        rep(i, 0, 2)
        {
            if(i == c) continue;

            res = min(res, cost[n][i] + f(n-1, i));
        }

        return dp[n][c] = res;
    }

    int estimateCost(vector<string> houses)
    {
        int n = sz(houses);
        rep(i, 0, n-1)
        {
            stringstream vp(houses[i]);
            vp >> cost[i][0] >> cost[i][1] >> cost[i][2];
        }
        memset(dp, -1, sizeof(dp));
        return f(n-1, 3);
    }
};