
struct SparseTable{
  vector<vector<int>> table;
  int n, k;
    
  // O(NlogN) time and memory preprocessing
  SparseTable(vector<int> &arr){
    n = arr.size();
    k = 32 - __builtin_clz(n); // highest set bit
    table = vector<vector<int>>(n, vector<int>(k));
    for (int i = 0; i < n; i++) table[i][0] = arr[i];
    for (int j = 1; j < k; j++){
      rep(i, 1, n){
        if(i + (1 << j) - 1 > n) continue;
        table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
      }
    }
  }
		
// O(1) query	
  int minimum(int l, int r){
    int len = r - l + 1;
    int k = 31 - __builtin_clz(len); // highest set bit
    return min(table[l][k], table[r - (1 << k) + 1][k]);
  }
};
