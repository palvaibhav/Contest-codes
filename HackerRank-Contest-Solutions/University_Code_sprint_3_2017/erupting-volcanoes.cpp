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

int n, m;
int grid[305][305];

void floodfill(int x, int y, int w){
    grid[x][y] += w;

    for(int times = 1; times < n; times++){
        w--;
        if(w == 0)
            break;
        for(int i = x - times; i <= x + times; i++)
            if(i >= 0 && i < n && y - times >= 0)
                grid[i][y - times] += w;

        for(int i = x - times; i <= x + times; i++)
            if(i >= 0 && i < n && y + times < n)
                grid[i][y + times] += w;

        for(int j = y - times + 1; j <= y + times - 1; j++)
            if(j >= 0 && j < n && x - times >= 0)
                grid[x - times][j] += w;

        for(int j = y - times + 1; j <= y + times - 1; j++)
            if(j >= 0 && j < n && x + times < n)
                grid[x + times][j] += w;

    }
}

int main()
{
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            grid[i][j] = 0;
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++){
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        floodfill(x, y, w);
    }

    int ans = -1;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            ans = max(ans, grid[i][j]);

    /*for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            printf("%d ", grid[i][j]);
        printf("\n");
    }*/

    printf("%d", ans);

	return 0;
}


