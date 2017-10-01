/* -------------------------------------------------

Author :- Vaibhav Pal
College :- Norhtern India Engineering College, New Delhi
Coding Handle :- underdog_eagle

----------------------------------------------------*/


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000

int main()
{
    char str[4];
    scanf("%s", str);
    (str[1] == '+') ? printf("%d", (str[0] + str[2] - 2*('0'))) : printf("%d", (str[0] - str[2]));

	return 0;
}


