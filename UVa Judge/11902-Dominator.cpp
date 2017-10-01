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

int t, n, case_no;
int adj_mat[105][105];
bool visited[105];
bool ans[105][105];

void dfs_1(int node) {
	visited[node] = true;
	for (int i = 0; i < n; i++) {
		if (adj_mat[node][i] && !visited[i]) 
			dfs_1(i);
	}
}

void dfs_2(int node ,int x) {
	if (node != x) {
		visited[node] = true;
		ans[x][node] = false;
		for (int i = 0; i < n; i++) {
			if (adj_mat[node][i] && !visited[i])
				dfs_2(i, x);
		}
	}
}

int main() 
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	cin >> t;
	case_no = 0;
	while (t--) {
		case_no++;
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> adj_mat[i][j];

		for (int i = 0; i < n; i++)
			visited[i] = false;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				ans[i][j] = true;
		
		// Marking all the nodes reachable from node 0.		
		dfs_1(0);
        
        // Clearing the node which is not reachable from node 0 from the ans matrix.
		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				for (int j = 0; j < n; j++){
					ans[i][j] = false;
					ans[j][i] = false;
				}
			}
		}
        
        // Finding out for every node what nodes it dominates.
		for (int x = 0; x < n; x++) {
			for (int i = 0; i < n; i++)
				visited[i] = false;
			dfs_2(0, x);
		}
        

        // Output
		cout << "Case " << case_no << ":\n";
		for (int i = 0; i < n; i++) {
			cout << "+";
			for (int j = 0; j < 2 * n - 1; j++)
				cout << "-";
			cout << "+\n";

			for (int j = 0; j < n; j++) {
				ans[i][j] ? cout << "|Y" : cout << "|N";
			}
			cout << "|\n";
		}
		cout << "+";
		for (int j = 0; j < 2 * n - 1; j++)
			cout << "-";
		cout << "+\n";
	}

	//system("pause");
	return 0;
}