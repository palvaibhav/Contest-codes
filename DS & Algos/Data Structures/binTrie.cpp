#include <bits/stdc++.h>

using namespace std;

struct Node {
  Node* ch[2];
  
  void add(int pos, int x) {
    if (pos < 0) return;
    int bit = ((x & (1 << pos)) != 0);
    if (ch[bit]) {
      ch[bit]->add(pos - 1, x);
    } else {
      ch[bit] = new Node();
      ch[bit]->add(pos - 1, x);
    }
  }
  
  // Finds max val obtained when x is paired with a no. in trie in O(BITLEN)
  void maximize(int pos, int x, int& res) {
    if (pos < 0) return;
    int bit = ((x & (1 << pos)) != 0);
    if (ch[!bit]) {
      res |= (1 << pos);
      ch[!bit]->maximize(pos - 1, x, res);
    } else if (ch[bit]) {
      ch[bit]->maximize(pos - 1, x, res);
    }
  }
  
  void minimize(int pos, int x, int& res) {
    if (pos < 0) return;
    int bit = ((x & (1 << pos)) != 0);
    if (ch[bit]) {
      ch[bit]->minimize(pos - 1, x, res);
    } else if (ch[!bit]) {
        res |= (1 << pos);
      ch[!bit]->minimize(pos - 1, x, res);
    }
  }

  void del() {
    if (ch[0]) ch[0]->del();
    if (ch[1]) ch[1]->del();
    delete(this);
  }
};
