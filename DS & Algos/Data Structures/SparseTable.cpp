//follows 1-indexing of array

struct SparseTableMN{
    static const int MAXN = 1e5+5, LOGMAXN = 20;
    int table[MAXN][LOGMAXN];
    int n, k;

    // O(NlogN) time and memory preprocessing
    SparseTableMN(vector<int> &arr){
        n = arr.size()-1;
        k = 31 - __builtin_clz(n); // highest set bit
        for(int i=1;i<=n;i++) table[i][0] = arr[i];
        for(int j=1;j<=k;j++){
            for(int i=1;i<=n;i++){
                if(i + (1<<j) - 1 > n) continue;
                table[i][j] = min(table[i][j-1], table[i+(1<<(j-1))][j-1]);
            }
        }
    }

    // O(1) query
    int minimum(int l, int r){
        int len = r-l+1;
        int k = 31 - __builtin_clz(len); // highest set bit
        return min(table[l][k], table[r-(1<<k)+1][k]);
    }
};

struct SparseTableMX{
    static const int MAXN = 1e5+5, LOGMAXN = 20;
    int table[MAXN][LOGMAXN];
    int n, k;

    // O(NlogN) time and memory preprocessing
    SparseTableMX(vector<int> &arr){
        n = arr.size()-1;
        k = 31 - __builtin_clz(n); // highest set bit
        for(int i=1;i<=n;i++) table[i][0] = arr[i];
        for(int j=1;j<=k;j++){
            for(int i=1;i<=n;i++){
                if(i + (1<<j) - 1 > n) continue;
                table[i][j] = max(table[i][j-1], table[i+(1<<(j-1))][j-1]);
            }
        }
    }

    // O(1) query
    int maximum(int l, int r){
        int len = r-l+1;
        int k = 31 - __builtin_clz(len); // highest set bit
        return max(table[l][k], table[r-(1<<k)+1][k]);
    }
};
