#include <bits/stdc++.h>

using namespace std;

template<int maxn, int alpha>
struct Trie {
  vector<vector<int>> tr;
  int next_new = 1;
  
  Trie() {
    tr = vector<vector<int>>(maxn, vector<int>(alpha, -1));
  }
  
  void insert(string s) {
    int pos, cur_node = 0;
    for (pos = 0; pos < (int)s.size(); pos++) {
      if (tr[cur_node][s[pos] - 'a'] == -1) {
        tr[cur_node][s[pos] - 'a'] = next_new++;
      }
      cur_node = tr[cur_node][s[pos] - 'a']; 
    }
  }
  
  bool find(string s) {
    int pos, cur_node = 0;
    for (pos = 0; pos < (int)s.size(); pos++) {
      if (tr[cur_node][s[pos] - 'a'] != -1) {
        cur_node = tr[cur_node][s[pos] - 'a'];
      } else {
        break;
      }
    }
    return (pos == (int)s.size());
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  return 0;
}
