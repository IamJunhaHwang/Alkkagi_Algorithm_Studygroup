#include<iostream>
#include<stack>
using namespace std;

int main() {
	int arr[5][19] = { 0, };
	int x;
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 18; j++) {
			cin >> x;
			arr[i][j] = x;
		}
	}

	arr[1][0] = 1;
	arr[2][0] = 1;
	arr[3][0] = 1;
	arr[4][0] = 1;

	//각 나라 총점이 5인지
	for (int i = 1; i <= 4; i++) {
		int temp = 0;
		for (int j = 1; j <= 16; j = j + 3) {
			temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2];
			if (temp != 5)
				arr[i][0] = 0;
		}
	}
	
	//조별로 승, 패 각각 더한게 같은지
	for (int i = 1; i <= 4; i++) {
		int win = 0, defeat = 0;
		win = arr[i][1] + arr[i][4] + arr[i][7] + arr[i][10] + arr[i][13] + arr[i][16];
		defeat = arr[i][3] + arr[i][6] + arr[i][9] + arr[i][12] + arr[i][15] + arr[i][18];
		if (win != defeat)
			arr[i][0] = 0;
	}
	
	//무승부 스택에 넣고
	//넣을 때 같은게 있으면 pop, 다르면 push
	for (int i = 1; i <= 4; i++) {
		stack<int> s;
		for (int j = 2; j <= 17; j = j + 3) {
			if (arr[i][j] == 0)
				continue;
			if (s.empty())
				s.push(arr[i][j]);
			else {
				if (s.top() == arr[i][j])
					s.pop();
				else
					s.push(arr[i][j]);
			}
		}
		if (!s.empty())
			arr[i][0] = 0;
	}
	

	for (int i = 1; i <= 4; i++) {
		cout << arr[i][0] << " ";
	}

	return 0;
}
