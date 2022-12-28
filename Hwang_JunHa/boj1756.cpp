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

		if (depth < 0) {  // ���ڰ� �����ִµ� ���쿡 ������ ������ 0 ���
			cout << 0 << endl;
			return 0;
		}

		for (int j = depth; j >= 0; j--) {
			if (oven[j] < pizza) {  // ���� �������� ���� ������ �� ũ�� ���� �� ��
				depth--;

				if (j == 0) {  // ������ ������������ ������ ���ڰ� ���� ������ ������ ��� ����� �� ��
					cout << 0 << endl;
					return 0;
				}
			}
			else {  // ���� ��
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