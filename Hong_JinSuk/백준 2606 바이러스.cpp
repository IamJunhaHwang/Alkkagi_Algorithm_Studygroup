#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int com[101][101] = { 0, };
int n;
vector<int> temp;
int cnt = 0;
bool visit[101];

void search (int key) {
	visit[key] = 1; // 방문한거 체크
	for (int i = 1; i < n + 1; i++) {
		if (com[key][i] == 1 && !visit[i]) { // 방문 안했고 연결된거
			cnt++;
			search(i);
		}
	}
}

int main() {

	int k;
	cin >> n >> k;

	int x, y;
	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		com[x][y] = 1;
		com[y][x] = 1;
	}

	search(1);

	cout << cnt;

	return 0;
}