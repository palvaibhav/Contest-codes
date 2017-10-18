/* -------------------------------------------------

Author :- Vaibhav Pal
College :- Northern India Engineering College, New Delhi
Coding Handle :- underdog_eagle
Title :-

----------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define INF 1000000000
#define nl '\n'
#define sp ' '
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define fo(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)

ll T, N, Q;

int main()
{
	FAST_IO
	cin >> T;

	while (T--) {
		cin >> N >> Q;
		vvi preCycles(N + 1, vi(1));//stores prefix path sums for N cycles.
		fo(i, 1, N) {
			int A;
			cin >> A;
			fo(j, 1, A) {
				int w;
				cin >> w;
				preCycles[i].pb(preCycles[i][j - 1] + w);
			}
		}

		vector<pair<pair<int, int>, int> > in_out(N + 1); // stores min distance between in-out nodes for each inner cycles.
		vi bigCycle(N + 1); //stores edge weights between N inner cycles.
		fo(i, 1, N) {
			int v1, v2, w;
			cin >> v1 >> v2 >> w;
			in_out[i].first.second = v1;
			in_out[i % N + 1].first.first = v2;
			bigCycle[i] = w;
		}

		// Calculating min distances between in-out vertexes for each inner cycles.
		fo(i, 1, N) {
			int a = in_out[i].first.first, b = in_out[i].first.second, n = preCycles[i].size() - 1;
			if (a > b) swap(a, b);
			in_out[i].second = min(preCycles[i][b - 1] - preCycles[i][a - 1], preCycles[i][n] - (preCycles[i][b - 1] - preCycles[i][a - 1]));
		}

		vi preComp(N + 1); // stores out-out min distances between inner cycles.
		fo(i, 1, N) 
			preComp[i] = preComp[i - 1] + bigCycle[i] + in_out[i % N + 1].second;

		while (Q--) {
			int v1, c1, v2, c2;
			cin >> v1 >> c1 >> v2 >> c2;
			if (c1 > c2) swap(c1, c2), swap(v1, v2);

			int dis1 = 0, dis2 = 0, a, b, n;
			//Constructing dis1 (clockwise)
			a = v1, b = in_out[c1].first.second, n = preCycles[c1].size() - 1;
			if (a > b) swap(a, b);
			dis1 += min(preCycles[c1][b - 1] - preCycles[c1][a - 1], preCycles[c1][n] - (preCycles[c1][b - 1] - preCycles[c1][a - 1]));

			dis1 += (preComp[c2 - 1] - preComp[c1 - 1]);

			dis1 -= in_out[c2].second;

			a = v2, b = in_out[c2].first.first, n = preCycles[c2].size() - 1;
			if (a > b) swap(a, b);
			dis1 += min(preCycles[c2][b - 1] - preCycles[c2][a - 1], preCycles[c2][n] - (preCycles[c2][b - 1] - preCycles[c2][a - 1]));

			//constructing dis2(anti-clockwise)
			dis2 += (preComp[N] - (preComp[c2 - 1] - preComp[c1 - 1]));
			dis2 -= in_out[c1].second;

			a = v1, b = in_out[c1].first.first, n = preCycles[c1].size() - 1;
			if (a > b) swap(a, b);
			dis2 += min(preCycles[c1][b - 1] - preCycles[c1][a - 1], preCycles[c1][n] - (preCycles[c1][b - 1] - preCycles[c1][a - 1]));

			a = v2, b = in_out[c2].first.second, n = preCycles[c2].size() - 1;
			if (a > b) swap(a, b);
			dis2 += min(preCycles[c2][b - 1] - preCycles[c2][a - 1], preCycles[c2][n] - (preCycles[c2][b - 1] - preCycles[c2][a - 1]));

			//taking min of dis1 & dis2 as the final answer.
			cout << min(dis1, dis2) << nl;
		}

	}

    //system("pause");
	return 0;
}