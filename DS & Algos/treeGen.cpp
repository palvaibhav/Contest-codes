#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;

long long r(long long l, long long r){
  return rand() % (r - l + 1) + l;
}

int pa[N];

int root(int u) { return pa[u] == u ? u : pa[u] = root(pa[u]); }

void merge(int u, int v) {
  u = root(u);
  v = root(v);
  if (u > v) swap(u, v);
  pa[v] = u;
}

bool isSame(int u, int v) { return root(u) == root(v); }

int main(int argc, char* argv[]){
  long long seed = atoi(argv[1]);
  srand(seed);
  int n = 1000;
  cout << n << "\n";
  for (int i = 1; i <= n; i++) {
    cout << r(1, 2e5) << " ";
    pa[i] = i;
  }
  cout << "\n";
  for (int i = 1; i < n; i++) {
    while (1) {
      int u = r(1, n);
      int v = r(1, n);
      if (!isSame(u, v)) {
        cout << u << " " << v << "\n";
        merge(u, v);
        break;
      }
    }
  }  
}
