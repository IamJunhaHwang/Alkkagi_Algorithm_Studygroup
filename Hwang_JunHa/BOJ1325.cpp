#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int N, M;
int a, b;
int node;
int len = 0;
int maxlen = -1;
int cnt = 0;

int arr[10001];
int res[10001];
int visit[10001];

vector <pair<int, int>> v1[10001];
queue <int> q1;

int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		
		v1[b].push_back(make_pair(a, 0));
	}

	for (int i = 1; i <= N; i++) {		// 노드별로 BFS 작동시키기
		if (v1[i].empty()) continue;	// 해당 노드의 진출 간선이 없으면 continue

		q1.push(i);
		len++;
		visit[i]++;


		while (!q1.empty()) {		// 해당 노드의 진출 간선과 연결된 노드들을 큐를 이용해 BFS 실행
			node = q1.front();
			q1.pop();

			for (int j = 0; j < v1[node].size(); j++) {
				int next = v1[node][j].first;

				if (visit[next] == 0) {		// 노드에 방문할 수 있다면 해킹할 수 있는 컴퓨터 대수 + 1
					q1.push(next);
					len++;
				}

				visit[next]++;
			}
		}

		for (int x = 1; x <= N; x++)		// 출발 노드에서 BFS가 모두 끝났으면 visit 초기화
			visit[x] = 0;

		arr[i] = len;			// 방문한 노드의 길이 저장. 출발 노드 i
;
		len = 0;
	}

	for (int i = 1; i <= N; i++) {		// 각 노드별 길이 중 가장 긴 길이를 찾는다.
		maxlen = max(maxlen, arr[i]);
	}

	for (int i = 1; i <= N; i++) {		// 가장 긴 길이를 가진 노드들을 찾는다.
		if (arr[i] == maxlen)
			res[cnt++] = i;
	}

	sort(res, res + cnt);		// 찾은 노드들을 정렬

	for (int i = 0; i<cnt; i++)
		cout << res[i] << endl;




	return 0;
}