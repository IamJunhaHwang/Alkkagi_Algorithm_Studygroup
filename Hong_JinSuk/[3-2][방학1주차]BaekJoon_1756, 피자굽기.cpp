#include<iostream>
#include<vector>

using namespace std;

int D, N;
vector<int> Oven;
vector<int> Pizza;

int main() {

	cin >> D >> N;

	int num;
	for (int i = 1; i < D+1; i++) {
		cin >> num;
		Oven.push_back(num);
	}

	for (int i = 0; i < N; i++) {
		cin >> num;
		Pizza.push_back(num);
	}

	int Loc = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 1; j < D+1; j++) {
			if (j == D) { // 피자가 오븐에 걸리지 않고 밑바닥에 들어가면
				D--;
				Loc = j;
			}
			else if (Pizza[i] > Oven[j]) { // 피자가 오븐에 걸리면
				D = j - 1;
				Loc = j;
			}
		}
	}

	cout << Loc;

	return 0;
}