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

	while (Left < Right) { // 다 해볼때까지 반복
		int sum = Liq[Left] + Liq[Right];

		if (abs(sum) < abs(B)) {
			B = sum; // 더 작아지면 교체
		}
		if (B == 0) break;

		// 합이 음수면 양수를 더해줘야하고
		// 합이 양수면 음수를 더해줘야한다.
		if (sum < 0) Left++;
		else Right--;
	}

	cout << B;
	return 0;
}