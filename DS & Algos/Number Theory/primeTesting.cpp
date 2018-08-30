/* -------------------------------------------------

Author :- Vaibhav Pal
College :- Northern India Engineering College, New Delhi
Coding Handle :- underdog_eagle
Title :-

----------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define INF 1000000000000000000          // 10^18
#define nl '\n'
#define sp ' '
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
#define fo(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)

ll _sieve_size;
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound) {
	_sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= _sieve_size; i++) {
		if (bs[i]) {
			for (ll j = i*i; j <= _sieve_size; j += i) bs[j] = 0;
			primes.pb((int)i);
		}
	}
}

bool isPrime(ll N) {
	if (N <= _sieve_size) return bs[N];
	for (int i = 0; i < (int)primes.size(); i++)
		if (N % primes[i] == 0) return false;
	return true;
}


int main()
{
	FAST_IO

		clock_t start = clock();
	sieve(10000000);
	clock_t end = clock();

	cout << "Last Prime upto 10^7 :- " << primes[primes.size() - 1] << nl;
	clock_t start1 = clock();
	isPrime(9999991);
	clock_t end1 = clock();

	cout << "Sieve time :- " << (double)(end - start) / CLOCKS_PER_SEC << nl;
	cout << "Prime test time :- " << (double)(end1 - start1) / CLOCKS_PER_SEC << nl;

	//system("pause");
	return 0;
}
