#include <iostream>
#include <vector>

using namespace std;

const int N = 16;

vector<string> dp[N][N];

void findKbitCombinations(int k) {
    string s = "";
    for (int i = 0; i <= k; ++i) {
        dp[i][0].push_back(s);
        s = s + "0";
    }

    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= i; ++j) {
            for (auto s : dp[i - 1][j]) dp[i][j].push_back("0" + s);

            for (auto s : dp[i - 1][j - 1]) dp[i][j].push_back("1" + s);
        }
    }

    for (int i = 1; i <= k; ++i) {
        for (auto s : dp[k][i]) {
            cout << s << ' ';
        }
        cout << "\n";
    }
}

int main() {

    findKbitCombinations(5);

    return 0;
}