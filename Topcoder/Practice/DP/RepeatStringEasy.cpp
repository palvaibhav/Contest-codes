#include <bits/stdc++.h>
using namespace std;

class RepeatStringEasy{
    public:
    	int lcs(string X, string Y, int m, int n)
		{
            int L[m + 1][n + 1];
            int i, j;

            for (i = 0; i <= m; i++)
            {
                for (j = 0; j <= n; j++)
                {
                    if (i == 0 || j == 0)
                        L[i][j] = 0;

                    else if (X[i - 1] == Y[j - 1])
                        L[i][j] = L[i - 1][j - 1] + 1;

                    else
                        L[i][j] = max(L[i - 1][j], L[i][j - 1]);
                }
            }

            return L[m][n];
        }
    
    	int maximalLength(string s){
            int ans = 0, n = s.size();
            for(int i = 0; i < n; i++){
                ans = max(ans, 2 * lcs(s.substr(0, i), s.substr(i, n - i), i, n - i));
            }
            return ans;
        }
};