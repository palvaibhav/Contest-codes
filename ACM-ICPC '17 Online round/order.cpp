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
typedef vector<ii> vii;
typedef vector<int> vi;
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

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

int main()
{
	FAST_IO
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif 
	int t;
	cin >> t;
	while (t--) {
		int a1, a2, a3;
		int b1, b2, b3;
		int c1, c2, c3;
		cin >> a1 >> a2 >> a3;
		cin >> b1 >> b2 >> b3;
		cin >> c1 >> c2 >> c3;
		bool f;
		f = (c1 >= b1 && c2 >= b2 && c3 >= b3) && (c1 > b1 || c2 > b2 || c3 > b3) && (b1 >= a1 && b2 >= a2 && b3 >= a3) && (b1 > a1 || b2 > a2 || b3 > a3);
		if (f) {
			cout << "yes\n";
			continue;
		}
		f = (b1 >= c1 && b2 >= c2 && b3 >= c3) && (b1 > c1 || b2 > c2 || b3 > c3) && (c1 >= a1 && c2 >= a2 && c3 >= a3) && (c1 > a1 || c2 > a2 || c3 > a3);
		if (f) {
			cout << "yes\n";
			continue;
		}
		f = (c1 >= a1 && c2 >= a2 && c3 >= a3) && (c1 > a1 || c2 > a2 || c3 > a3) && (a1 >= b1 && a2 >= b2 && a3 >= b3) && (a1 > b1 || a2 > b2 || a3 > b3);
		if (f) {
			cout << "yes\n";
			continue;
		}
		f = (a1 >= c1 && a2 >= c2 && a3 >= c3) && (a1 > c1 || a2 > c2 || a3 > c3) && (c1 >= b1 && c2 >= b2 && c3 >= b3) && (c1 > b1 || c2 > b2 || c3 > b3);
		if (f) {
			cout << "yes\n";
			continue;
		}
		f = (b1 >= a1 && b2 >= a2 && b3 >= a3) && (b1 > a1 || b2 > a2 || b3 > a3) && (a1 >= c1 && a2 >= c2 && a3 >= c3) && (a1 > c1 || a2 > c2 || a3 > c3);
		if (f) {
			cout << "yes\n";
			continue;
		}
		f = (a1 >= b1 && a2 >= b2 && a3 >= b3) && (a1 > b1 || a2 > b2 || a3 > b3) && (b1 >= c1 && b2 >= c2 && b3 >= c3) && (b1 > c1 || b2 > c2 || b3 > c3);
		if (f) {
			cout << "yes\n";
			continue;
		}

		cout << "no\n";
	}
	return 0;
}