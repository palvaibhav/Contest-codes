/* -------------------------------------------------

Author :- Vaibhav Pal
College :- Northern India Engineering College, New Delhi
Coding Handle :- underdog_eagle
Title :- Coin Change problem ----> O(n*sum)

----------------------------------------------------*/
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <algorithm>
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
    int n, sum;
    cin >> n;
    int val[n+1];
    for(int i = 1; i <= n; i++)
        cin >> val[i];
    cin >> sum;

    int minCoins[sum + 1]; // DP table
    minCoins[0] = 0;
    for(int i = 1; i <= sum; i++)
        minCoins[i] = INT_MAX;

    for(int i = 1; i <= sum; i++){
        for(int j = 1; j <= n; j++)
            if(val[j] <= sum)
                minCoins[i] = min(minCoins[i], minCoins[i - val[j]] + 1);
    }

    cout << minCoins[sum] << nl;

    return 0;
}
