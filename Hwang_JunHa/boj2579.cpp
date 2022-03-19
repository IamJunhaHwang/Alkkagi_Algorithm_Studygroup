#include <iostream>
#include <algorithm>

using namespace std;

int N, cnt = 0;
int stair[300];
int d[300];  // index칸까지의 최댓값을 저장하는 배열(dp 테이블)

int main() {
	int res = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> stair[i];
	}

	d[0] = stair[0];
	d[1] = stair[0] + stair[1];
	d[2] = max(stair[1]+stair[2], stair[0] + stair[2]);  // 마지막 계단은 꼭 밟아야 함에 주의!
	
	for (int i = 3; i < N; i++) {
		d[i] = max(d[i - 3] + stair[i] + stair[i - 1], d[i - 2] + stair[i]);  // 마지막 계단은 꼭 밟아야 하므로 <마지막 직전> 계단을 밟는 경우, 안 밟는 경우를 생각해야 한다.
	}

	cout << d[N - 1];

	return 0;
}