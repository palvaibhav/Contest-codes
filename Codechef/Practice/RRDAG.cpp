/* -------------------------------------------------

Author :- Vaibhav Pal
College :- Northern India Engineering College, New Delhi
Coding Handle :- underdog_eagle
Title :- Codechef Problem ----> RRDAG(DAGs & Topological sorting)

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

int main()
{
    FAST_IO
    int n;
    cin >> n;
    char AdjMat[n + 5][n + 5], newEdge[n + 5][n + 5];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            newEdge[i][j] = '0';
    int outdeg[n+5];
    bool vis[n+5];
    memset(vis, 0, sizeof vis);
    memset(outdeg, 0, sizeof outdeg);
    for(int i = 0; i < n; i++){
        cin >> AdjMat[i];
        for(int j = 0; j < n; j++){
            if(AdjMat[i][j] == '1')
                outdeg[i]++;
        }
    }
    int cnt = 0, v;
    while(1){
        for(v = n - 1; v >= 0; v--){
            if(vis[v] || outdeg[v]) continue;
            for(int j = 0; j < n; j++){
                if(AdjMat[j][v] == '1'){
                    outdeg[j]--;
                    continue;
                }
                if(j == v || vis[j]) continue;
                newEdge[j][v] = '1';
                cnt++;
            }
            vis[v] = true;
            break;
        }
        if(v < 0) break;
    }

    cout << cnt << nl;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(newEdge[i][j] == '1')
                cout << i + 1 << sp << j + 1 << nl;

    return 0;
}
