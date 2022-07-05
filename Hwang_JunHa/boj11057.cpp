# include <iostream>

using namespace std;

int N;
int arr[1003][10];	// dp 테이블(1003: 자리수, 10: 각 자릿수에는 0~9까지 나올 수 있음)
int ans = 0;

int main() {					

	cin >> N;

	for (int i = 0; i < 10; i++)		// 1의 자리 수는 오르막 수를 각각 1개씩 갖는다.
		arr[1][i] = 1;

	if (N == 1) {
		cout << 10 << endl;
		return 0;
	}

	for (int i = 2; i <= N; i++) {		// N 자릿수까지의 오르막 수
		for (int j = 0; j < 10; j++) {	// N 자릿수에서 0~9가 나올 때의 오르막 수 각각 계산
			for(int z=j; z<10; z++)		// 오르막 수 이므로 만약, 2가 나온다면 그 다음 자리에는 2와 같거나 큰 수가 와야함.
				arr[i][j] += arr[i - 1][z];
			arr[i][j] %= 10007;
		}
	}

	for (int i = 0; i < 10; i++) {
		ans += arr[N][i];
		ans %= 10007;
	}

	cout << ans << endl;

	return 0;
}