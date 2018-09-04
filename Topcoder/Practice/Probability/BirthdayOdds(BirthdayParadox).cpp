#include <bits/stdc++.h>
using namespace std;

#define sz(o) ((int)o.size())
#define all(o) o.begin(), o.end()
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define repr(i, a, b) for(int i = (a); i >= (b); i--)
#define INF 1000000000000000000LL
#define MOD 1000000007
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

class BirthdayOdds{
public:
    int minPeople(int minOdds, int daysInYear){
        int k = 1;
        double target = 1 - (double)minOdds/100;
        double y = 1;
        while(y > target){
            k++;
            y *= (1-(double)(k-1)/daysInYear);
        }
        return k;
    }
};
