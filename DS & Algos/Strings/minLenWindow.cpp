/* -------------------------------------------------

Author :- Vaibhav Pal
College :- Northern India Engineering College, New Delhi
Coding Handle :- underdog_eagle
Title :- Find the smallest window in a string(Text) containing all characters of another string(Pattern).

----------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define INF 1000000000000000000          // 10^18
#define nl '\n'
#define sp ' '
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
#define fo(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)

const int MAXCHARS = 256;

// Time complexity :- O(N) -------> Linear.
string findMinLenWindow(string T, string P) {
	int len1 = T.length();
	int len2 = P.length();
	int hash_T[MAXCHARS] = { 0 }, hash_P[MAXCHARS] = { 0 };

	fo(i, 0, len2 - 1) hash_P[P[i]]++; 
	int cnt = 0, st = 0, min_len = INT_MAX, start_idx = -1;
	fo(j, 0, len1 - 1) {
		hash_T[T[j]]++;

		// Increase counter of chars found till now of the pattern.
		if (hash_P[T[j]] != 0 && hash_T[T[j]] <= hash_P[T[j]])
			cnt++;

		// If this condition is not true then we haven't found any valid window yet.
		if (cnt == len2) {
			// Removing Extra or useless occurences of chars in current window by 
			// sliding start of the window towards right by 1 at a time.
			while (hash_P[T[st]] == 0 || hash_T[T[st]] > hash_P[T[st]]) {
				if(hash_T[T[st]] > hash_P[T[st]])
					hash_T[T[st]]--;
				st++;
			}

			// Updation step for global answer.
			int win_len = j - st + 1;
			if (win_len < min_len) {
				min_len = win_len;
				start_idx = st;
			}
		}
	}

	// If this is true then we didn't found any valid window.
	if (start_idx == -1) {
		cout << "No valid window found!" << nl;
		return "";
	}

	cout << "Length of Min length valid window in Text :- " << min_len << nl;
	return T.substr(start_idx, min_len);
}

int main()
{
	FAST_IO

	string Text = "this is a test string";
	string Pattern = "tist";
    cout << "Min length substring :- " << findMinLenWindow(Text, Pattern) << nl;
	//system("pause");
	return 0;
}