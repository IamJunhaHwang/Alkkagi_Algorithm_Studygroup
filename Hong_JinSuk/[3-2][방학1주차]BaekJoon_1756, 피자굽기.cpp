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
			if (j == D) { // ���ڰ� ���쿡 �ɸ��� �ʰ� �عٴڿ� ����
				D--;
				Loc = j;
			}
			else if (Pizza[i] > Oven[j]) { // ���ڰ� ���쿡 �ɸ���
				D = j - 1;
				Loc = j;
			}
		}
	}

	cout << Loc;

	return 0;
}