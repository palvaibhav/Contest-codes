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

const int N = 1005;
int n;
char grid[N][N];
int grundy[N][N];
int dr[] = {-1, 0, -1};
int dc[] = {0, -1, -1};

int calculateMEX(set<int> s){
    int mex = 0;
    while(s.find(mex) != s.end())
        mex++;
    return mex;
}

int calculateGrundy(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= n || grid[x][y] == 'X')
        return -1;
    if(grundy[x][y] != -1)
        return grundy[x][y];

    set<int> s;
    s.insert(calculateGrundy(x, y - 1));
    s.insert(calculateGrundy(x - 1, y));
    s.insert(calculateGrundy(x - 1, y - 1));

    int mex = calculateMEX(s);
    grundy[x][y] = mex;
    return mex;
}

void init(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%s", grid[i]);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            grundy[i][j] = -1;
    }
}

int main()
{
    int q;
    scanf("%d", &q);
    while(q--){
        init();
        vector<pair<int, int> > coordinates;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 'K')
                    coordinates.push_back(make_pair(i, j));
        }

        int allxor = 0;
        for(int i = 0; i < coordinates.size(); i++){
            int res = calculateGrundy(coordinates[i].first, coordinates[i].second);
            allxor = (allxor^res);
        }

        int cnt = 0;
        if(allxor > 0){
            for(int i = 0; i < coordinates.size(); i++){
                for(int j = 0; j < 3; j++){
                    int grundyNum1 = calculateGrundy(coordinates[i].first + dr[j], coordinates[i].second + dc[j]);
                    int grundyNum2 = calculateGrundy(coordinates[i].first, coordinates[i].second);
                    if((allxor ^ grundyNum1 ^ grundyNum2) == 0)
                        cnt++;
                }
            }
        }

        (allxor > 0) ? printf("WIN %d\n", cnt) : printf("LOSE\n");
    }

    return 0;
}
