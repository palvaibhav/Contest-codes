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

#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define INF 1000000000
#define nl '\n'
#define sp ' '
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define fo(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)

ll a, b, d;
ll _sieve_size;
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound) {
  _sieve_size = upperbound + 1;
  bs.set();
  bs[0] = bs[1] = 0;
  for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {

    for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
    primes.push_back((int)i);
} }

ll numDiv(ll N) {
  ll PF_idx = 0, PF = primes[PF_idx], ans = 1;
  while (N != 1 && (PF * PF <= N)) {
    ll power = 0;
    while (N % PF == 0) { N /= PF; power++; }
    ans *= (power + 1);
    PF = primes[++PF_idx];
  }
  if (N != 1) ans *= 2;
  return ans;
}

int main()
{
    FAST_IO
    int t;
    sieve(10000000);
    cin >> t >> a >> b;
    while(t--){
        cin >> d;
        ll ans = 0;
        for(ll num = a; num <= b; num++){
            ll temp = num;
            while(temp % d == 0)
                temp /= d;
            ans += numDiv(temp);
        }

        cout << ans << nl;
    }

    return 0;
}
