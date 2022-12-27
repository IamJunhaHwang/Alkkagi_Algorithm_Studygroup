#include<iostream>
#include<vector>

using namespace std;

int d, n;
vector<int> Oven;
vector<int> Pizza;

int main() {

	cin >> d >> n;

	int num;
	Oven.push_back(NULL); // 그냥 1부터 넣고 싶어서...
	for (int i = 1; i < d+1; i++) {
		cin >> num;
		Oven.push_back(num);
	}

	for (int i = 0; i < n; i++) {
		cin >> num;
		Pizza.push_back(num);
	}

	for (int i = 1; i < d + 1; i++) {
		// 어차피 아래가 커봤자 위에서 내려가면 다 내려가짐
		if (i == d) break;
		if (Oven[i + 1] > Oven[i]) Oven[i + 1] = Oven[i];
	}

	int Loc = d;
	for (int j = 0; j < n; j++) {
		int cnt = 0;
		for (int i = d; i > 0; i--) {
			cnt++;
			if (Pizza[j] <= Oven[i]) { //피자가 i까지 내려가면
				Loc -= cnt;
				d = i - 1;
				if (d == 0) Loc = -1; // 꽉차면 0
				break; // 다음피자로
			}
			if (i == 1) {
				Loc = -1;
				d = 1;
			}
		}
	}

	cout << Loc + 1;

	return 0;
}