#include<iostream>
#include<vector>
using namespace std;

int n, m;

int main() {

	cin >> n >> m;

	vector<vector<int>> Block(n, vector<int>(m, 0));

	// Block 입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int num;
			cin >> num;
			Block[i][j] = num;
		}
	}

	vector<int> num_n;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		num_n.push_back(num);

		for (int j = 0; j < n; j++) {
			// 0이 아니면 앞에서 본 모양으로 꽉 채워줌 
			if (Block[j][i] != 0) Block[j][i] = num;
		}
	}

	vector<int> num_m;
	for (int i = n - 1; n >= 0; i--) {
		int num;
		cin >> num;
		num_m.push_back(num);

		for (int j = 0; j < m; j++) {
			if (Block[i][j] != 0) {
				// 최대값보다 크다면 최대값으로 맞춰준다.
				if (num < Block[i][j]) {
					Block[i][j] = num;
				}
			}
		}
		if (i == 0) break; // 왜 알아서 못나가지? ㅋㅋㅋㅋ
	}

	// n=2 m=3
	int M = n;
	for (int i = 0; i < n; i++) {
		int isRight = 0;
		int isWrong = 0;
		M--;
		for (int j = 0; j < m; j++) {
			if (Block[i][j] == num_m[M]) isRight++;
			if (Block[i][j] > num_m[M]) isWrong++;
		}
		if (!isRight || isWrong) {
			cout << -1;
			return 0;
		}
	}

	int N = 0;
	for (int j = 0; j < m; j++) {
		int isRight = 0;
		int isWrong = 0;
		for (int i = 0; i < n; i++) {
			if (Block[i][j] == num_n[N]) isRight++;
			if (Block[i][j] > num_n[N]) isWrong++;
		}
		N++;
		if (!isRight || isWrong) {
			cout << -1;
			return 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << Block[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}