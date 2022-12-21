#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int n;
int arr[10001] = {0, };
int dp[10001] = {0, };
int cnt = 3;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	if (n == 1) {
		cout << arr[0] << endl;
		return 0;
	}
	else if (n == 2) {
		cout << arr[0] + arr[1] << endl;
		return 0;
	}

	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	dp[2] = max({ dp[0] + arr[2], dp[1], arr[1] + arr[2] });

	for(int cnt=3; cnt<n; cnt++){
		dp[cnt] = max({ dp[cnt - 2] + arr[cnt], dp[cnt - 1], dp[cnt - 3] + arr[cnt - 1] + arr[cnt] });
	}

	cout << dp[n - 1] << endl;

	return 0;
}