#include <iostream>
#include <algorithm>

using namespace std;

int d, n, pizza, depth, res;
int oven[300001];

int main() {
	cin >> d >> n;

	depth = d-1;

	for (int i = 0; i < d; i++) {
		cin >> oven[i];

		if (i > 0) {
			if (oven[i] > oven[i - 1]) {
				oven[i] = oven[i - 1];
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		cin >> pizza;

		if (depth < 0) {  // 피자가 남아있는데 오븐에 공간이 없으면 0 출력
			cout << 0 << endl;
			return 0;
		}

		for (int j = depth; j >= 0; j--) {
			if (oven[j] < pizza) {  // 오븐 지름보다 피자 지름이 더 크면 피자 안 들어감
				depth--;

				if (j == 0) {  // 오븐의 마지막공간에 마지막 피자가 들어가지 않으면 공간이 없어서 못들어 간 것
					cout << 0 << endl;
					return 0;
				}
			}
			else {  // 피자 들어감
				//cout << pizza << "   " << depth << endl;
				res = depth;
				depth--;
				break;
			}
			
		}
	}

	cout << res+1 << endl;

	return 0;
}