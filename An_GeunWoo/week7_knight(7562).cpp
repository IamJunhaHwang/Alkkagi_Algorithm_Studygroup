#include<iostream>
#include<queue>
using namespace std;

int main() {
	int n, len, s_x, s_y, d_x, d_y;
	int dx[8] = { 2,2,1,1,-1,-1,-2,-2 };
	int dy[8] = { 1,-1,2,-2,2,-2,1,-1 };
	int map[300][300];
	int x, y;
	queue<pair<int, int>> q;

	cin >> n;
	for (int k = 0; k < n; k++) {
		cin >> len;
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				map[i][j] = -1;
			}
		}
		cin >> s_x >> s_y;
		cin >> d_x >> d_y;
		map[s_x][s_y] = 0;
		q.push({ s_x,s_y });

		while (!q.empty()) {
			auto cur = q.front();
			q.pop();
			for (int i = 0; i < 8; i++) {
				x = cur.first + dx[i];
				y = cur.second + dy[i];

				if (x < 0 || x >= len || y < 0 || y >= len)
					continue;
				if (map[x][y] >= 0)
					continue;

				map[x][y] = map[cur.first][cur.second] + 1;
				q.push({ x,y });
			}
		}
		cout << map[d_x][d_y] << endl;
	}
	return 0;
}