#include<iostream>
using namespace std;

int max(int a, int b) { //크기 비교하는 사용자 정의 함수
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

int main() {
	int n;
	int arr[301];
	int dp[301];

	cin >> n;

	for (int i = 1; i <= n; i++) { //dp와 인덱스를 맞추기 위해 1부터 삽입
		cin >> arr[i];
	}

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]);
	
	for (int i = 4; i <= n; i++) {
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
	}

	cout << dp[n];


	return 0;
}
