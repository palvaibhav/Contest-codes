/* -------------------------------------------------

Author :- Vaibhav Pal
College :- Northern India Engineering College, New Delhi
Coding Handle :- underdog_eagle
Title :- Codechef Problem ----> ALTARAY(Simple DP)

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

const int N = (int)(1e5 + 5);
ll n, A[N], len[N];
int main()
{
    FAST_IO
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> A[i], len[i] = 1;

        for(int i = n - 2; i >= 0; i--){
            if(A[i+1] >= 0 && A[i] < 0)
                len[i] += len[i+1];
            else if(A[i+1] < 0 && A[i] > 0)
                len[i] += len[i+1];
        }

        for(int i = 0; i < n; i++)
            cout << len[i] << sp;
        cout << nl;
    }

    return 0;
}
