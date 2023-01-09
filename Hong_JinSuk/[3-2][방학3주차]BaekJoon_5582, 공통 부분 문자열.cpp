#include<iostream>
#include<algorithm>

using namespace std;

string F, S;

int dp[4002][4002] = {0, };
int MAX = 0;

int main() {

	cin >> F >> S;

	for (int i = 0; i < F.length(); i++) {
		for (int j = 0; j < S.length(); j++) {			
			if (F[i] == S[j]) {
				dp[i+1][j+1] = dp[i][j] + 1;
			}
			MAX = max(MAX, dp[i+1][j+1]);
		}
	}

	cout << MAX;

	return 0;
}
