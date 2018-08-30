/* -------------------------------------------------

Author :- Vaibhav Pal
College :- Norhtern India Engineering College, New Delhi
Coding Handle :- underdog_eagle

----------------------------------------------------*/


#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000

int n, m, s;
char grid[105][105];

//          {N, E, S, W}
//int dr[] = {-1, 0, 1, 0};
//int dc[] = {0, 1, 0, -1};

int sticker_cnt, x, y;
char dir;

void find_robot() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 'N') {
				dir = 'N';
				x = i;
				y = j;
				return;
			}
			else if (grid[i][j] == 'S') {
				dir = 'S';
				x = i;
				y = j;
				return;
			}
			else if (grid[i][j] == 'L') {
				dir = 'E';
				x = i;
				y = j;
				return;
			}
			else if (grid[i][j] == 'O') {
				dir = 'W';
				x = i;
				y = j;
				return;
			}
		}
	}
}

void change_dir(char input) {
	if (input == 'D') {
		if (dir == 'N')
			dir = 'E';
		else if (dir == 'E')
			dir = 'S';
		else if (dir == 'S')
			dir = 'W';
		else if (dir == 'W')
			dir = 'N';

	}
	else if (input == 'E') {
		if (dir == 'N')
			dir = 'W';
		else if (dir == 'E')
			dir = 'N';
		else if (dir == 'S')
			dir = 'E';
		else if (dir == 'W')
			dir = 'S';
	}
}

void move(int dr, int dc) {
	int temp_x = x + dr;
	int temp_y = y + dc;

	if (temp_x >= 0 && temp_x < n && temp_y >= 0 && temp_y < m && grid[temp_x][temp_y] != '#') {
		x = temp_x;
		y = temp_y;
		if (grid[x][y] == '*') {
			sticker_cnt++;
			grid[x][y] = '.';
		}
	}
}

void move_util() {
	if (dir == 'N')
		move(-1, 0);
	else if (dir == 'E') 
		move(0, 1);
	else if (dir == 'S') 
		move(1, 0);
	else if (dir == 'W') 
		move(0, -1);	
}

int main() 
{

	while (1) {
		cin >> n >> m >> s;
		
		if (n == 0 && m == 0 && s == 0)
			break;

		for (int i = 0; i < n; i++)
			cin >> grid[i];

		find_robot();
		sticker_cnt = 0;
		
		char inst;
		for (int i = 0; i < s; i++) {
			cin >> inst;
			
			if (inst == 'D' || inst == 'E')
				change_dir(inst);
			else if (inst == 'F')
				move_util();			
		}
		
		cout << sticker_cnt << "\n";
	}


	//system("pause");
	return 0;
}