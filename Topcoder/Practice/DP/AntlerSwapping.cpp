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

class AntlerSwapping{
public:
    int n;
    bool canCycle[1<<16];
    int maxCycles[1<<16];

    int getmin(vi antler1, vi antler2, int capacity){
        n = sz(antler1);
        rep(mask, 0, (1<<n)-1){
            vi ant;
            rep(i, 0, n-1){
                if(mask&(1<<i)){
                    ant.push_back(antler1[i]);
                    ant.push_back(antler2[i]);
                }
            }
            sort(all(ant));
            canCycle[mask] = true;
            for(int i = 0; i < sz(ant); i += 2){
                if(ant[i+1] - ant[i] > capacity){
                    canCycle[mask] = false;
                    break;
                }
            }
        }
        rep(mask, 1, (1<<n)-1){
            for(int sub = mask; sub > 0; sub = ((sub-1) & mask)){
                if(canCycle[sub] and (sub == mask or maxCycles[mask-sub] > 0)){
                    maxCycles[mask] = max(maxCycles[mask], 1 + maxCycles[mask-sub]);
                }
            }
        }
        int c = maxCycles[(1<<n)-1];
        return (c > 0) ? n-c : -1;
    }
};


