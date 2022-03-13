#include <iostream>

using namespace std;

int N, fidx, re = 0;
int c[50] = { 0, };

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> c[i];
	}

	if (N == 1) {  // N==1이면 매수할 필요 없다.
		cout << 0;
		return 0;
	}

	int maxn = -1;

	while (1) {
		for (int i = 1; i < N; i++) {  // 0번째 인덱스에는 다솜이의 표가 있으므로 1부터 max값을 찾는다.
			if (maxn <= c[i]) {
				maxn = c[i];
				fidx = i;  // max값의 index
			}
		}

		if (maxn >= c[0]) {
			c[fidx]--;
			maxn = -1;  // 나의 표수를 올린 후 다시 처음부터 max값을 찾아야 하므로
			c[0]++;
			re++;
		}
		else
			break;
		
	}


	cout << re << endl;

	return 0;
}