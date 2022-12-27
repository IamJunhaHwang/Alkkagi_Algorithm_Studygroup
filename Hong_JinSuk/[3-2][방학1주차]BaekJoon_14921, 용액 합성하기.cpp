#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

vector<int> Liq;
int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		Liq.push_back(num);
	}

	int Left = 0;
	int Right = n - 1;

	int B = 200000000;

	while (Left < Right) { // �� �غ������� �ݺ�
		int sum = Liq[Left] + Liq[Right];

		if (abs(sum) < abs(B)) {
			B = sum; // �� �۾����� ��ü
		}
		if (B == 0) break;

		// ���� ������ ����� ��������ϰ�
		// ���� ����� ������ ��������Ѵ�.
		if (sum < 0) Left++;
		else Right--;
	}

	cout << B;
	return 0;
}