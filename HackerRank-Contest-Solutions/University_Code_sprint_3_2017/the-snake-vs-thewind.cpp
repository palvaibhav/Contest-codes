/* -------------------------------------------------

Author :- Vaibhav Pal
College :- Norhtern India Engineering College, New Delhi
Coding Handle :- underdog_eagle

----------------------------------------------------*/


#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000

int n, x, y;
char wind_dir, snake_dir;
int grid[65][65];
//     {n, w, s, e}
int dr1[] = { -1, 0, 1, 0 };
int dc1[] = { 0, -1, 0, 1 };
char dir[] = { 'n', 'w', 's', 'e' };

map<char, int> dr, dc;

void init_dir() {
	if (wind_dir == 'n') {
		if (x == n - 1 && y == 0)
			snake_dir = 'n';
		else if (x == n - 1 && y == n - 1)
			snake_dir = 'n';
		else if (x == 0 && y == n - 1)
			snake_dir = 'w';
		else if (x == 0 && y == 0)
			snake_dir = 'e';

	}
	else if (wind_dir == 'e') {
		if (x == n - 1 && y == 0)
			snake_dir = 'e';
		else if (x == n - 1 && y == n - 1)
			snake_dir = 'n';
		else if (x == 0 && y == n - 1)
			snake_dir = 's';
		else if (x == 0 && y == 0)
			snake_dir = 'e';
	}
	else if (wind_dir == 's') {
		if (x == n - 1 && y == 0)
			snake_dir = 'e';
		else if (x == n - 1 && y == n - 1)
			snake_dir = 'w';
		else if (x == 0 && y == n - 1)
			snake_dir = 's';
		else if (x == 0 && y == 0)
			snake_dir = 's';
	}
	else if (wind_dir == 'w') {
		if (x == n - 1 && y == 0)
			snake_dir = 'n';
		else if (x == n - 1 && y == n - 1)
			snake_dir = 'w';
		else if (x == 0 && y == n - 1)
			snake_dir = 'w';
		else if (x == 0 && y == 0)
			snake_dir = 's';
	}
}

bool can_move(int i, int j) {
	return (i >= 0 && i < n && j >= 0 && j < n && grid[i][j] == 0);
}

void move() {
	x += dr.find(snake_dir)->second;
	y += dc.find(snake_dir)->second;
}

char opp_dir(char _dir){
    if(_dir == 'n')
        return 's';
    else if(_dir == 's')
        return 'n';
    else if(_dir == 'e')
        return 'w';
    else
        return 'e';
}

pair<char, char> get_per_dirs(){
    if(wind_dir == 'n' || wind_dir == 's')
        return make_pair('w', 'e');
    else return make_pair('n', 's');
}

bool explore_options(){

    if(can_move(x + dr.find(wind_dir)->second, y + dc.find(wind_dir)->second)){
        snake_dir = wind_dir;
        return true;
    }
    pair<char, char> per_dirs = get_per_dirs();

    if(can_move(x + dr.find(per_dirs.first)->second, y + dc.find(per_dirs.first)->second)){
        snake_dir = per_dirs.first;
        return true;
    }
    else if(can_move(x + dr.find(per_dirs.second)->second, y + dc.find(per_dirs.second)->second)){
        snake_dir = per_dirs.second;
        return true;
    }
    else if(can_move(x + dr.find(opp_dir(wind_dir))->second, y + dc.find(opp_dir(wind_dir))->second)){
        snake_dir = opp_dir(wind_dir);
        return true;
    }

    return false;
}

void move_snake() {
	int time = 1;
	grid[x][y] = time;
	time++;

	while(1){
        while(can_move(x + dr.find(snake_dir)->second, y + dc.find(snake_dir)->second)){
            move();
            grid[x][y] = time;
            time++;
        }
        bool flag = explore_options();
        if(!flag)
            return;

        if(snake_dir == opp_dir(wind_dir)){
            move();
            grid[x][y] = time;
            time++;
            flag = explore_options();
        }

        if(!flag)
            return;
	}
}

int main()
{
	cin >> n;
	cin >> wind_dir;
	cin >> x >> y;

    dr.insert(pair<char, int>('n', -1));
	dr.insert(pair<char, int>('w', 0));
	dr.insert(pair<char, int>('s', 1));
	dr.insert(pair<char, int>('e', 0));

	dc.insert(pair<char, int>('n', 0));
	dc.insert(pair<char, int>('w', -1));
	dc.insert(pair<char, int>('s', 0));
	dc.insert(pair<char, int>('e', 1));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			grid[i][j] = 0;

	init_dir();
	move_snake();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << grid[i][j] << " ";
		cout << "\n";
	}

	return 0;
}


