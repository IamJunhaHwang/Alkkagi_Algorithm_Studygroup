# include <iostream>
# include <queue>
# include <algorithm>

using namespace std;

queue<pair<int, int>> q;
int c, I, s_x, s_y, e_x, e_y;
int board[300][300];
int visit[300][300];
int mov[8][2] = {{-2,1}, {-1,2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

void BFS() {
	q.push(make_pair(s_x, s_y));

	while (!q.empty()) {  // 큐가 빌 때까지
		pair<int, int> p = make_pair(q.front().first, q.front().second);
		q.pop();

		if (visit[p.first][p.second] >= 1)		// 이미 방문한 곳이면 볼 필요 없음.
			continue;

		visit[p.first][p.second] = 1;			// 방문하지 않은 곳이면 방문한 것을 기록
		
		if (p.first == e_x && p.second == e_y) {	// 도착 지점에 도착하면 종료.
			cout << board[e_x][e_y] << endl;
			return;
		}


		for (int i = 0; i < 8; i++) {  
			if ((p.first - mov[i][0]) >= I || (p.first - mov[i][0]) < 0 || (p.second - mov[i][1]) < 0 || (p.second - mov[i][1]) >= I)	// 체스판을 벗어날 수 없다.
				continue;
			pair<int, int> tmp = make_pair(p.first - mov[i][0], p.second - mov[i][1]);		// 나이트가 움직일 수 있다면 해당 칸을 큐에 넣는다.
			q.push(tmp);
			board[tmp.first][tmp.second] = board[p.first][p.second] + 1;		// 해당 칸에는 움직인 횟수 기록.  (전에 이동했던 횟수 + 1을 해줌)
		}
	}
	if(q.empty())			// 해당 칸으로 이동 못하면
		cout << 0 << endl;
}

int main() {					// 나이트의 이동
	
	cin >> c;

	for (int i = 0; i < c; i++) {
		cin >> I;

		cin >> s_x >> s_y;    // 출발 좌표
		board[s_x][s_y] = 0;  // start
		
		cin >> e_x >> e_y;    // 도착 좌표
		if (s_x == e_x && s_y == e_y) {  // 같은 위치일 경우
			cout << '0' << endl;
			continue;
		}

		BFS();
		for (int i = 0; i < 300; i++) {			// 한 번의 케이스가 끝나면 초기화
			for (int j = 0; j < 300; j++) {
				visit[i][j] = 0;
				board[i][j] = 0;
			}
		}

		while (!q.empty()) q.pop();		// 한 번의 케이스가 끝나면 초기화
	}


	return 0;
}