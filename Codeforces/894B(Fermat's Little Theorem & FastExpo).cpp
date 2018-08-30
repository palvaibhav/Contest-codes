/* -------------------------------------------------

Author :- Vaibhav Pal
College :- Northern India Engineering College, New Delhi
Coding Handle :- underdog_eagle
Title :-

----------------------------------------------------*/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<pll> vpll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;

#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define INF 1000000000000000000          // 10^18
#define nl '\n'
#define sp ' '
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
#define bg begin()
#define en end()
#define fo(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)

inline ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
inline ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

const ll M = (ll)(1e9 + 7);

ll getPow(ll n, ll m) { return (((n - 1) % (M - 1)) * ((m - 1) % (M - 1))) % (M - 1); } // Fermat's Little Theorem.

// O(logN)
ll fastExpo(ll a, ll n) { 
	if (n == 0) return 1;
	else if (n == 1) return a;
	ll ans = fastExpo(a, n / 2) % M;
	return (n % 2 == 0) ? ((ans % M) * (ans % M)) % M : ((((ans % M) * (ans % M)) % M) * (a % M)) % M;
}

int main()
{
	FAST_IO
    #ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
    #endif
	ll n, m, k;
	cin >> n >> m >> k;
	if (k == -1 && (n + m) % 2 != 0)
		cout << "0";
	else {
		ll r = getPow(n, m);
		cout << fastExpo(2, r);
	}	
	return 0;
}