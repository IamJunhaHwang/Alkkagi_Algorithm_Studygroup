#include<iostream>
using namespace std;

int n1, n2, cnt = 0;
int map[101][101];
int visit[101];

void dfs(int virus) {
	visit[virus] = 1;
	for (int i = 1; i <= n1; i++) {
		if (visit[i] != 1 && map[virus][i] == 1) {
			cnt++;
			dfs(i);
		}
	}
}

int main() {
	int x, y;
	cin >> n1;
	cin >> n2;
	for (int i = 0; i < n2; i++) {
		cin >> x >> y;
		map[x][y] = map[y][x] = 1;
	}

	dfs(1);

	cout << cnt;

	return 0;
}

/*
#include<iostream>
using namespace std;

int n2;
int arr[100][2];
int check[101] = { 0, };

void search(int virus) {
	int temp;
	for (int i = 0; i < n2; i++) {
		if (arr[i][0] == virus) {
			arr[i][0] = -1;

			if (check[arr[i][1]] != 1) {
				check[arr[i][1]] = 1;
				temp = arr[i][1];
				arr[i][1] = -1;
				search(temp);
			}
			else {
				arr[i][1] = -1;
			}
		}
		else if (arr[i][1] == virus) {
			arr[i][1] = -1;

			if (check[arr[i][0]] != 1) {
				check[arr[i][0]] = 1;
				temp = arr[i][0];
				arr[i][0] = -1;
				search(temp);
			}
			else {
				arr[i][0] = -1;
			}
		}
	}
}

int main() {
	int n1;
	cin >> n1;
	cin >> n2;
	for (int i = 0; i < n2; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}

	search(1);

	int cnt = 0;
	for (int i = 2; i <= n1; i++) {
		if (check[i] == 1)
			cnt++;
	}
	cout << cnt;

	return 0;
}
*/
