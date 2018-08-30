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

class MatchNumbersEasy
{
public:

    string dp[51];
    
    string f(vi &matches, int n)
    {
        if(dp[n] != "") return dp[n];
        string res = "";
        rep(i, 0, sz(matches)-1)
        {
            if(n >= matches[i])
            {
                string x = f(matches, n - matches[i]);
                x = x + (char)(i+'0');
                if(x[0] != '0')
                {
                    if(sz(x) > sz(res)) res = x;
                    else if(sz(x) == sz(res) && x.compare(res) > 0) res = x;
                }
            }
        }
        return dp[n] = res;
    }

    string maxNumber(vi matches, int n)
    {
        string ans = f(matches, n);
        if(sz(ans) == 0) ans += '0';
        return ans;
    }
};
