# include <iostream>
# include <vector>
# include <queue>
# include <algorithm>
# define INF 1e9

using namespace std;

vector <pair<int, int>> city[1001];  // 정점
priority_queue<pair<int, int>> qu;

int N, M;					// 정점과 노드 개수
int from, to, val;
int start, fin;

int dist[1001];		// 최단거리 갱신할 배열, 출발점에서 특정 정점(index)까지의 최단 거리 값.

bool compare(pair<int, int>a, pair<int, int>b) {	// 똑같은 간선(A->B)일 때, 비용이 더 적은 것이 벡터의 앞에 오게 정렬
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first < b.first;
}

int main() {					// 최소 비용 구하기

	cin >> N >> M;

	fill(dist, dist + N + 1, INF);  // dist 채우기

	for (int i = 0; i < M; i++) {
		cin >> from >> to >> val;
		city[from].push_back({to,val});
	}

	for (int i = 0; i < N; i++) {
		if (city[i].empty()) continue;

		sort(city[i].begin(), city[i].end(), compare);
	}

	cin >> start >> fin;

	qu.push({ 0, start });	// 시작점 Cost, 시작점 Vertex
	dist[start] = 0;		// 시작점 최단거리

	while (!qu.empty()) {
		int cost = -qu.top().first;		// 방문점 Cost
		int here = qu.top().second;		// 방문점 Vertex

		qu.pop();

		for (int i = 0; i < city[here].size(); i++) {
			int next = city[here][i].first;			// 다음 방문할 점
			int nextcost = city[here][i].second;	// 다음 방문할 비용

			if (dist[next] > dist[here] + nextcost) {
				// 저장된 dist[next]보다  현재 점을 거쳐서 갈 경우가 거리가 더 짧으면 갱신 후 큐에 삽입
				dist[next] = dist[here] + nextcost;
				qu.push({ -dist[next], next });  // 우선 순위 큐는 Max Heap 구조이므로 
				// 가장 작은 값이 가장 큰 값이 되게 "-"를 곱해서 큐에 넣고 뺀다.
			}
		}
	}
	
	cout << dist[fin] << endl;

	return 0;
}