#include<iostream>
using namespace std;

int main() {
	int N;
	int res = 0;
	cin >> N;
	int dp[1001][11] = { 0, };

	for (int i = 1; i <= 10; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		dp[i][1] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 2; j <= 10; j++) {
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
			dp[i][j] = dp[i][j] % 10007;
		}
	}

	for (int i = 1; i <= 10; i++) {
		res += dp[N][i];
	}
	cout << res % 10007;

	return 0;
}