/* -------------------------------------------------
 
Author :- Vaibhav Pal
College :- Northern India Engineering College, New Delhi
Coding Handle :- underdog_eagle
Title :- Lowest Prime DIvisor Seive + segtree use
 
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
#define fo(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)
 
inline ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
inline ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
 
const ll SIEVE_SIZE = (ll)(1e6);
int lpd[SIEVE_SIZE + 5];
vi a;
vi st;
int n, m;
 
inline void sieve() {
	lpd[0] = lpd[1] = 1;
	for (ll i = 2; i <= SIEVE_SIZE; i++) {
		if (lpd[i] == -1) {
			lpd[i] = i;
			for (ll j = i * i; j <= SIEVE_SIZE; j += i) 
				if (lpd[j] == -1) lpd[j] = i;
		}
	}
}
 
inline int left(int p) { return p << 1; }
inline int right(int p) { return (p << 1) + 1; }
inline int mid(int L, int R) { return (L + R) / 2; }
 
inline void build(int p, int L, int R) {
	if (L == R) 
		st[p] = lpd[a[L]];
	else {
		build(left(p), L, mid(L, R));
		build(right(p), mid(L, R) + 1, R);
		st[p] = max(st[left(p)], st[right(p)]);
	}
}
 
inline void update(int p, int L, int R, int i, int j) {
	if (i > R || j < L) return;
	if (L == R) {
		a[L] /= lpd[a[L]];
		st[p] = lpd[a[L]];
		return;
	}
	if (st[p] != 1) {
		update(left(p), L, mid(L, R), i, j);
		update(right(p), mid(L, R) + 1, R, i, j);
		st[p] = max(st[left(p)], st[right(p)]);
	}
}
 
inline int query(int p, int L, int R, int i, int j) {
	if (i > R || j < L) return 0;
	if (L >= i && R <= j) return st[p];
	if (st[p] != 1) {
		int p1 = query(left(p), L, mid(L, R), i, j);
		int p2 = query(right(p), mid(L, R) + 1, R, i, j);
		return max(p1, p2);
	}
	else
		return 1;
}
 
int main()
{
	FAST_IO
    #ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
    #endif
	fo(i, 0, SIEVE_SIZE) lpd[i] = -1;
	sieve();
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		a.assign(n + 1, 0);
		fo(i, 1, n) cin >> a[i];
		st.assign(4 * n, 0);
		build(1, 1, n);		
		while (m--) {
			int type, L, R;
			cin >> type >> L >> R;
			if (type == 0)
				update(1, 1, n, L, R);
			else 
				cout << query(1, 1, n, L, R) << sp;
		}
		cout << nl;
	}
	return 0;
}