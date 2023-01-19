//#include<iostream>
//using namespace std;
//
//int dp[100010][4] = { 0, };
//
//int lion(int x, int c) {
//	if (x == 1) {
//		return dp[x][c] = 1;
//	}
//	if (dp[x][c] != 0) {
//		return dp[x][c];
//	}
//	else {
//		if (c == 1) {
//			return dp[x][c] = (lion(x - 1, 2) + lion(x - 1, 3)) % 9901;
//		}
//		else if (c == 2) {
//			return dp[x][c] = (lion(x - 1, 1) + lion(x - 1, 3)) % 9901;
//		}
//		else {
//			return dp[x][c] = (lion(x - 1, 1) + lion(x - 1, 2) + lion(x - 1, 3)) % 9901;
//		}
//	}
//}
//
//int main() {
//	int n;
//	cin >> n;
//
//	int res = lion(n, 1) + lion(n, 2) + lion(n, 3);
//
//	cout << res % 9901;
//
//	return 0;
//}

#include<iostream>
using namespace std;

int dp[100010][4] = { 0, };

int main() {
	int n;
	cin >> n;

	dp[1][1] = 1;
	dp[1][2] = 1;
	dp[1][3] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % 9901;
		dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % 9901;
		dp[i][3] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) % 9901;
	}

	int res = (dp[n][1] + dp[n][2] + dp[n][3]) % 9901;

	cout << res;

	return 0;
}
