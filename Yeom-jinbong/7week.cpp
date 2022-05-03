/*#include <iostream>
#include<queue>
using namespace std;
int main() {
	int c;
	cin >> c;
	int* arr = new int[c];
	for (int i = 0; i < c; i++) {
		queue<int>lx;
		queue<int>ly;
		int space;
		int now[2];
		int future[2];
		queue<int>lx2;
		queue<int>ly2;
		int index = 1;
		cin >> space;
		cin >> now[0];
		cin >> now[1];
		cin >> future[0];
		cin >> future[1];
		lx.push(now[0]);
		ly.push(now[1]);
		if (now[0] == future[0] && now[1] == future[1]) {
			arr[i] = 0;
		}
		else {
			while (1) {
				while (!lx.empty() && !ly.empty()) {
					if ((lx.front() + 2) == future[0] && (ly.front() + 1) == future[1]) {
						goto Exit;
					}
					else if ((lx.front() + 2) <= (space - 3) && (ly.front()+1) <= (space - 2)) {
						lx2.push(lx.front() + 2);
						ly2.push(ly.front() + 1);
					}
					if ((lx.front() + 1) == future[0] && (ly.front() + 2) == future[1]) {
						goto Exit;
					}
					else if ((lx.front() + 1) <= (space - 2) && (ly.front() + 2) <= (space - 3)) {
						lx2.push(lx.front() + 1);
						ly2.push(ly.front() + 2);
					}
					if ((lx.front() - 2) == future[0] && (ly.front() + 1) == future[1]) {
						goto Exit;
					}
					else if ((lx.front() - 2) >= 2 && (ly.front() + 1) <= (space - 2)) {
						lx2.push(lx.front() - 2);
						ly2.push(ly.front() + 1);
					}
					if ((lx.front() - 1) == future[0] && (ly.front() + 2) == future[1]) {
						goto Exit;
					}
					else if ((lx.front() - 1) >= 1 && (ly.front() + 2) <= (space - 3)) {
						lx2.push(lx.front() - 1);
						ly2.push(ly.front() + 2);
					}
					if ((lx.front() - 2) == future[0] && (ly.front() - 1) == future[1]) {
						goto Exit;
					}
					else if ((lx.front() - 2) >= 2 && (ly.front() - 1) >= 1) {
						lx2.push(lx.front() - 2);
						ly2.push(ly.front() - 1);
					}
					if ((lx.front() - 1) == future[0] && (ly.front() - 2) == future[1]) {
						goto Exit;
					}
					else if ((lx.front() - 1) >= 1 && (ly.front() - 2) >= 2) {
						lx2.push(lx.front() - 1);
						ly2.push(ly.front() - 2);
					}
					if ((lx.front() + 2) == future[0] && (ly.front() - 1) == future[1]) {
						goto Exit;
					}
					else if ((lx.front() + 2) <= (space - 3) && (ly.front() - 1) >= 1) {
						lx2.push(lx.front() + 2);
						ly2.push(ly.front() - 1);
					}
					if ((lx.front() + 1) == future[0] && (ly.front() - 2) == future[1]) {
						goto Exit;
					}
					else if ((lx.front() + 1) <= (space - 2) && (ly.front() - 2) >= 2) {
						lx2.push(lx.front() + 1);
						ly2.push(ly.front() - 2);
					}
					lx.pop();
					ly.pop();
				}
				index++;
				while (!lx2.empty() && !ly2.empty()) {
					lx.push(lx2.front());
					lx2.pop();
					ly.push(ly2.front());
					ly2.pop();
				}
			}
			Exit:
			arr[i] = index;
			index = 0;
		}
	}
	for (int i = 0; i < c; i++) {
		cout << arr[i] << endl;
	}
	delete[] arr;
	return 0;
}*/#include<iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int n, si, a, b, c, d;
int cnt[301][301]; // 최소 횟수 세는 배열
int dx[] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[] = { 2,1,-1,-2,-2,-1,1,2 };
queue<pair<int, int> > q;
void bfs() {

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();
		for (int k = 0; k < 8; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || ny < 0 || nx >= si || ny >= si) continue;
			if (cnt[nx][ny] == 0) {
				q.push(make_pair(nx, ny));
				cnt[nx][ny] = cnt[x][y] + 1;
			}
			if (nx == c && ny == d) break;
		}

	}
}

int main() {
	cin >> n; // n = x, m=y;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {

		cin >> si >> a >> b >> c >> d;
		if (a == c && b == d) arr[i] = 0; // 같은 수 일 경우 바로 0 출력
		else {                                              // 아닐경우
			q.push(make_pair(a, b));
			bfs();
			arr[i] = cnt[c][d];
			memset(cnt, 0, sizeof(cnt));
			while (!q.empty())q.pop();          // 큐랑 배열 초기화
		}
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}

}
