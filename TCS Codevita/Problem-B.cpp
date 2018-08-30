#include <bits/stdc++.h>
using namespace std;

int m, n, x1, y1;
bool visited[25][25];
char grid[25][25];
int ans[25][25];

int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

void bfs(int x, int y){
    queue<pair<int, int> > q;
    visited[x][y] = true;
    ans[x][y] = 1;
    q.push(make_pair(x, y));

    while(!q.empty()){
        pair<int, int> s = q.front();
        q.pop();

        for(int i = 0; i < 8; i++){
            x = s.first + dr[i];
            y = s.second + dc[i];

            if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 'T' && !visited[x][y]){
                ans[x][y] = ans[s.first][s.second] + 1;
                q.push(make_pair(x, y));
                visited[x][y] = true;
            }
        }
    }
}

int main(){

	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

    cin >> m >> n;
    cin >> x1 >> y1;

    for(int i = 0; i < m; i++)
        cin >> grid[i];

    memset(visited, false, sizeof(visited));
    memset(ans, 0, sizeof(ans));

    bfs(x1 - 1, y1 - 1);

    int final_ans = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++)
            final_ans = max(final_ans, ans[i][j]);
    }

    cout << final_ans;

	return 0;
}
