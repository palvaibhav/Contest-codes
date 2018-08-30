#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 1000001;
const int TYPE1 = 1, TYPE2 = 2, UP = 3, RIGHT = 4, DOWN = 5, LEFT = 6, DIFF = 3;
int k, a1, a2, b1, b2;
int grid[25][25];

// {UP,  RIGHT, DOWN, LEFT} ---> clockwise from UP
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int dir_change_1[] = {RIGHT, UP, LEFT, DOWN};
int dir_change_2[] = {LEFT, DOWN, RIGHT, UP};

pair<int, int> solve(int x, int y, int dir, int steps_cnt, int barrier_cnt){
    if(x == a1 && y == a2)
		return make_pair(steps_cnt, barrier_cnt);
	if(x < 0 || x >= k || y < 0 || y >= k)
		return make_pair(INF, INF);

	if(grid[x][y] == TYPE1){
		dir = dir_change_1[dir - DIFF];
		x += dr[dir - DIFF];
		y += dc[dir - DIFF];
		return solve(x, y, dir, steps_cnt + 1, barrier_cnt + 1);
	}
	else if(grid[x][y] == TYPE2){
		dir = dir_change_2[dir - DIFF];
		x += dr[dir - DIFF];
		y += dc[dir - DIFF];
		return solve(x, y, dir, steps_cnt + 1, barrier_cnt + 1);
	}
	else{
		x += dr[dir - DIFF];
		y += dc[dir - DIFF];
		return solve(x, y, dir, steps_cnt + 1, barrier_cnt);
	}

}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

    cin >> k;
    cin >> a1 >> a2;
    cin >> b1 >> b2;

    for(int i = 0; i < k; i++)
    	for(int j = 0; j < k; j++)
    		cin >> grid[i][j];


    pair<int, int> ans = make_pair(INF, INF);

    for(int i = UP; i <= LEFT; i++){
    	int x = b1 + dr[i - DIFF];
    	int y = b2 + dc[i - DIFF];
    	pair<int, int> temp = solve(x, y, i, 1, 0);
    	//cout << temp.first << " " << temp.second << "\n";

    	if(temp.first < ans.first)
    		ans = temp;
    	else if(temp.first == ans.first && temp.second < ans.second)
    		ans = temp;
    }

    (ans.first == INF) ? cout << "-1" : cout << ans.first << " " << ans.second;
}
