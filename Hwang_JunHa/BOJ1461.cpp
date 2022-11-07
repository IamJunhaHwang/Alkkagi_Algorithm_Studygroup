#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int book[51];
int N, tmp, M, check = 0;
int cnt = 0;
int walk = 0;

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> book[i];
	}

	sort(book, book + N);

	// 맨 마지막에 가는 위치는 다시 돌아오지 않아도 되므로 가장 많은 비용이 드는 곳으로 미리 계산해 놓는다.
	if (abs(book[0]) <= abs(book[N-1])) {  
		walk += abs(book[N-1]);
		for (int i = 0; i < M; i++) {
			if ((N - i - 1) < 0) break; // Out of Bounds 방지
			if (book[N-i-1] > 0) {
				book[N-i-1] = 0;  // 예를 들어, M이 2인데 -5 -4 11 과 같이 나오면 11만 들어가야 함.
				cnt++;
			}
		}
		N -= cnt;
		cnt = 0;
	}
	else {
		walk += abs(book[0]);
		for (int i = 0; i < M; i++) {
			if (book[i] < 0) {
				book[i] = 0;
				cnt++;
			}
		}
		check = check + cnt;
		cnt = 0;
	}

	// 배열의 앞부분부터 체크
	while ((check - N) < 0) {
		for (int i = check; i < N; i++) {
			if (book[i] < 0) {  // 음수의 경우
				walk += abs(book[i]) * 2;

				for (int j = 0; j < M; j++) {
					if (book[i+j] < 0) {
						book[i+j] = 0;
						cnt++;
					}

				}
				check += cnt;
				cnt = 0;
				break;
			}
			else {
				walk += abs(book[N - 1]) * 2;

				for (int j = N - 1; j > N - 1 - M; j--) {
					if (j < 0)break;  // Out of Bounds 방지
					if (book[j] >= 0) {
						book[j] = 0;
						cnt++;
					}
				}
				N -= cnt;
				cnt = 0;
				break;
			}
		}
		//cout << walk << endl;
	}

	cout << walk << endl;
	return 0;
}