#include<iostream>
#include<queue>
using namespace std;

int N, K;
int cnt = -1;
int visit[100001];

void bfs(int now) {
	queue<int> q;
	q.push(now);
	visit[now] = 1;
	int flag = 0;

	while (!q.empty() && flag == 0) {
		int size = q.size();
		for (int j = 0; j < size; j++) {
			int x = q.front();
			q.pop();

			if (x == K) {
				flag = 1;
				break;
			}

			for (int i = 0; i < 3; i++) {
				if (i == 0) {
					x += 1;
					if (x < 100001) {
						if (visit[x] == 0) {
							q.push(x);
							visit[x] = 1;
						}
					}
					x -= 1;
				}
				if (i == 1) {
					x -= 1;
					if (x < 100001) {
						if (visit[x] == 0) {
							q.push(x);
							visit[x] = 1;
						}
					}
					x += 1;
				}
				if (i == 2) {
					x *= 2;
					if (x < 100001) {
						if (visit[x] == 0) {
							q.push(x);
							visit[x] = 1;
						}
					}
					x /= 2;
				}
			}
		}
		cnt++;
	}
	cout << cnt;
}

int main() {
	cin >> N >> K;

	bfs(N);

	return 0;
}