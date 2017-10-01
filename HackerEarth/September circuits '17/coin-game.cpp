/* -------------------------------------------------

Author :- Vaibhav Pal
College :- Norhtern India Engineering College, New Delhi
Coding Handle :- underdog_eagle

----------------------------------------------------*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            int num;
            scanf("%d", &num);
            //In this problem for charlie to win the count of 2s in the input data set must be odd.
            while(!(num&1)){
                cnt++;
                num /= 2;
            }
        }

        (cnt&1) ? printf("Charlie\n") : printf("Alan\n");
    }
    return 0;
}
