#include <bits/stdc++.h>

using namespace std;

struct Bit {
  vector<int> bit;
  int n;
  
  Bit(vector<int>& v, int sz) {
    n = sz;
    bit.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      update(i, v[i]);
    }
  }
  
  void update(int i, int x) {
    for (; i <= n; i += (i & -i)) {
      bit[i] += x;
    }
  }
  
  int prefixQuery(int i) {
    int res = 0;
    for (; i > 0; i -= (i & -i)) {
      res += bit[i];
    }
    return res;
  }
  
  int rangeQuery(int l, int r) {
    return prefixQuery(r) - prefixQuery(l - 1);
  }
  
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  vector<int> v = {0, 1, 2, 3, 4, 5};
  Bit b(v, 5);
  cout <<  b.rangeQuery(1, 1) << "\n";
  return 0;
}
