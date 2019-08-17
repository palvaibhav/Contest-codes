#include <bits/stdc++.h>

using namespace std;

const int MOD = (int) 1e9+7;

void add(long long& a, long long b) {
  a += b;
  if (a >= MOD) a -= MOD;
}

void sub(long long& a, long long b) {
  a -= b;
  if (a < 0) a += MOD;
}

long long mul(long long a, long long b) {
  return ((a % MOD) * (b % MOD)) % MOD;
}

long long power(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

vector<pair<long long, int>> primeDecompose(long long n) {
  vector<pair<long long, int>> res;
  for (long long p = 2; p * p <= n; p++) {
    if (n % p == 0) {
      int cc = 0;
      while (n % p == 0) {
        n /= p;
        cc++;
      }
      res.emplace_back(p, cc);
    }
  }
  if (n > 1) res.emplace_back(n, 1);
  return res;
}

long long ncr(long long n, long long r){
  long long num = 1, den = 1;
  if(r > n / 2) r = n - r;
  for(long long i = 0; i < r; i++){
    num = mul(num, n - i);
    den = mul(den, i + 1);
  }
  num = mul(num, power(den, MOD - 2));
  return num;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}
