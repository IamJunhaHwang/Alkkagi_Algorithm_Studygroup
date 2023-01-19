#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[10010] = { 0, };
	int dp[10010] = { 0, };
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = max(arr[1] + arr[2], arr[2] + arr[3]);
	dp[3] = max(dp[3], arr[1] + arr[3]);

	for (int i = 4; i <= n; i++) {
		dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);
		dp[i] = max(dp[i - 1], dp[i]);
	}

	cout << dp[n];

	return 0;
}
