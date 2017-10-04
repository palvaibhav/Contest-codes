/* -------------------------------------------------

Author :- Vaibhav Pal
College :- Norhtern India Engineering College, New Delhi
Coding Handle :- underdog_eagle
Title :- SCC with floodfill

----------------------------------------------------*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000

char grid[20][65];
int n, m;
bool visited[20][65];

int dr[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dc[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

vi continents;

int dfs(int x, int y) {
	if (x < 1 || x > n || y < 1 || y > m || visited[x][y] || grid[x][y] == '.')
		return 0;
	int cnt = 1;
	visited[x][y] = true;

	for (int i = 0; i < 8; i++)
		cnt += dfs(x + dr[i], y + dc[i]);

	return cnt;

}

void dfsUtil() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!visited[i][j] && grid[i][j] == '#') {
				int landCnt = dfs(i, j);
				continents.push_back(landCnt);
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> grid[i][j];
			visited[i][j] = false;
		}

	dfsUtil();

	sort(continents.begin(), continents.end());

	int num = 0;
	for (int i = continents.size() - 1; i >= 0; i--)
		cout << "Island "<< ++num << ": " << continents[i] << "\n";
	cout << "Number of continents: " << continents.size() << "\n";

	//system("pause");

	return 0;
}

/*

5 6
######
##....
...###
######
######

15 60
####.#####.######.###.####.#######.#####.######.###.####.###
#########.#####...################.#####.######.###.####.###
########.#######...##############.#####.######.###.####.###.
..........#######...##############.#####.######.###.####.###
###.##.#.#.#.#.####..######.#####.######.###.####.###.......
##.######.##.#####...#########..............................
####.#####.######.###.####.#####.######.##.#####...#########
#########.#####...##############.######.##.#####...#########
########.#######...############.######.##.#####...#########.
..........#######...##########.#########.#####...###########
####.#####.######.###.####.############.#####...############
#########.#####...#####################.#####...############
########.#######...###################.#####...############.
..........#######...###################.#####...############
############...#.#.#.####..###########.#####...############.


*/
