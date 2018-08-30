/* -------------------------------------------------

Author :- Vaibhav Pal
College :- Northern India Engineering College, New Delhi
Coding Handle :- underdog_eagle
Title :- square root decomposition

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
#define INF 1000000000000000000         
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

int main()
{
	FAST_IO
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif

	int n, q;
	cin >> n >> q;
	int s = ceil(sqrt(n)); // block size sqrt(n)
	vi a(n), pref(n), lazy(s); // lazy for lazy updates
	vector<vector<int> > b(s, vi(1000005)); // works like map for int <-> int of size sqrt(n)*1000005
	fo(i, 0, n - 1) cin >> a[i];
	pref[0] = a[0];
	fo(i, 1, n - 1) pref[i] = pref[i - 1] ^ a[i]; // prefix xor-sum
	fo(i, 0, n - 1) b[i / s][pref[i]]++; // filling map for each block of size s = sqrt(n)

	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int idx, x;
			cin >> idx >> x;
			idx--; // for 0 based indexing
			int p = idx / s, y = a[idx] ^ x; // p is block no. of idx and y is the update
			fo(i, p + 1, s - 1) lazy[i] ^= y; // did lazy update from block p + 1 upto last block s - 1

			fo(i, idx, min(n - 1, (p + 1) * s - 1)) { // updating block p trivially
				if (b[p][pref[i]] > 0)
					b[p][pref[i]]--; // decrementing counter for deleting the old value
				pref[i] ^= y; // old value deleted from the prefix sum array
				b[p][pref[i]]++; // incrementing counter for new updated prefix sum	value			
			}
			a[idx] = x;
		}
		else {
			int idx, k;
			cin >> idx >> k;
			idx--; // for 0 based indexing
			int cnt = 0;
			int p = idx / s; // block no. of idx
			fo(i, 0, p - 1) cnt += b[i][k ^ lazy[i]]; // quering blocks from  0 upto p - 1 using xor property A = B ^ C <=> A ^ C = B. 

			fo(i, p * s, idx) // querying block p trivially
				cnt += (pref[i] == (k ^ lazy[p]));
			cout << cnt << nl; // final ans
		}
	}

	return 0;
}