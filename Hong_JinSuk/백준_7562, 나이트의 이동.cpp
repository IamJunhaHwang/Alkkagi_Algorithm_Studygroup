#include<iostream>
#include<vector>
#include<deque>

using namespace std;

int main() {

	int n;
	cin >> n;

	int Size;
	int start_x, start_y, end_x, end_y;

	int mx[8] = { 1,1,-1,-1,2,2,-2,-2 };
	int my[8] = { -2,2,-2,2,-1,1,-1,1 };
	// 나이트가 이동할 수 있는 모든 경우의 수

	for (int i = 0; i < n; i++) {

		cin >> Size >> start_x >> start_y >> end_x >> end_y;

		deque<pair<int, pair<int, int>>> v;
		v.push_back(make_pair(0, make_pair(start_x, start_y)));
		// count와 좌표 묶고, 시작은 0

		int visited[300][300] = { 0, }; // 여기 Size왜 안들어가냐..?
		visited[start_x][start_y]++;

		int cnt, x, y;
		while (1) { // 모든지점 다갈때까지 ㄱㄱ
			x = v.front().second.first;
			y = v.front().second.second;
			cnt = v.front().first;
			v.pop_front();


			for (int i = 0; i < 8; i++) {
				int next_x = x + mx[i];
				int next_y = y + my[i];
				//다음갈곳은 현재+이동한거리

				if (next_x<0 || next_y<0 || next_x>Size - 1 || next_y>Size - 1)
					continue;
				// 칸에 벗어나면 넘어감

				if (visited[next_x][next_y])
					continue;
				// 이미 지나간 지점이면 넘어감

				visited[next_x][next_y]++;
				v.push_back(make_pair(cnt + 1, make_pair(next_x, next_y)));
				//새로운곳 도착하면 count++, 그곳 넣어줌
			}

			if (x == end_x && y == end_y) {
				cout << cnt << endl;
				break;
			}
		}
	}

	return 0;
}