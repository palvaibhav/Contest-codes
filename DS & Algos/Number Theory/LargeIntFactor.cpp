#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
	while (a > 0 && b > 0) {
		if (a > b) {
		  a %= b;
		} else {
		  b %= a;
		}
	}
	return a + b;
}

// For multiplication of two very large Integers
long long mul(long long a, long long b, long long mod){
	long long res = 0;
	while (b > 0) {
		if (b & 1) {
			res += a;
			if (res >= mod) res -= mod;
		}
		a += a;
		if (a >= mod) a -= mod;
		b >>= 1;
	}
	return res;
}

//Fast expo
long long my_pow(long long a, long long b, long long mod){
	long long res = 1;
	while (b > 0) {
		if (b & 1) res = mul(res, a, mod);
		a = mul(a, a, mod);
		b >>= 1;
	}
	return res;
}		

// Miller-Rabin prime testing for large Integers
bool is_prime(long long n){
	if (n < 2) return false;
	vector<int> a = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}; 
	if (find(a.begin(), a.end(), n) != a.end()) return true;
	if (!(n & 1)) return false;
	long long d = n - 1, r = 0;
	while (!(d & 1)) {
		d >>= 1;
		r++;
	}
	for (int p : a) {
		long long x = my_pow(p, d, n);
		if (x == 1 || x == n - 1) continue;
		for (int i = 1; i < r; i++) {
			x = mul(x, x, n);
			if (x == 1) return false;
			if (x == n - 1) break;
		}
		if (x == n - 1) continue;
		return false;
	}
	return true;
}	

// Ploynomial function for pollard-rho
long long f(long long x, long long mod, long long c){
	long long y = mul(x, x, mod) + c;
	if (y > mod) y -= mod;
	return y;
}

//Prime Factorization of large Integers 
void pollard_rho(long long n, map<long long, long long>& p){
	if (n <= 1) return;
	if(is_prime(n)) {
		p[n]++;
		return;
	}
	for (long long c = 1; true; c++) {
		long long x = 2, y = 2, d = 1;
		while (d == 1) {
			x = f(x, n, c);
			y = f(f(y, n, c), n, c);
			d = gcd(abs(x - y), n);
		}
		if (d < n) {
			pollard_rho(d, p);
			pollard_rho(n / d, p);
			return;
		}
	} 
}

// Normal sqrt(n) Prime factorization function
void factorize(long long n, map<long long, long long>& p){
	if(is_prime(n)) return;
	while (!(n & 1)) {
		p[2]++;
		n >>= 1;
	}
	for (long long a = 3; a * a <= n; a++) {
		while (n % a == 0) {
			p[a]++;
			n /= a;
		}
	}
	if (n > 1) {
		p[n]++;
	}
}

// Given the prime factorization calculates numbers of divisors
long long calc(map<long long, long long>& p){
	long long res = 1;
	for (auto x : p) {
		res = (((x.second + 1) % MOD) * (res % MOD)) % MOD;
	}
	return res;
}
