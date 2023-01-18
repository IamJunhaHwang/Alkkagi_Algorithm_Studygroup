#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

int V, E;
int S;

int n1, n2, c;

vector <pair<int, int>> G[20001];
priority_queue<pair<int, int>> qu;  // < Cost, V >

int dist[20001];

bool compare(pair<int, int>a, pair<int, int>b) {	// 똑같은 간선(A->B)일 때, 비용이 더 적은 것이 벡터의 앞에 오게 정렬
    if (a.first == b.first)
        return a.second < b.second;
    else
        return a.first < b.first;
}

int main() {

    ios_base::sync_with_stdio(false);  // 이 두 라인(29~30) 안하면 시간 초과 
    cin.tie(NULL);

    cin >> V >> E;

    cin >> S;

    fill(dist, dist + V + 1, INF);

    for (int i = 0; i < E; i++) {
        cin >> n1 >> n2 >> c;
        
        G[n1].push_back({ n2, c });
    }

    for (int i = 1; i <= V; i++) {
        if (G[i].empty()) continue;

        sort(G[i].begin(), G[i].end(), compare);
    }

    qu.push({ 0, S });
    dist[S] = 0;

    while (!qu.empty()) {
        int cost = -qu.top().first;		// 방문점 Cost
        int here = qu.top().second;		// 방문점 Vertex

        qu.pop();

        for (int i = 0; i < G[here].size(); i++) {
            int next = G[here][i].first;			// 다음 방문할 점
            int nextcost = G[here][i].second;	// 다음 방문할 비용

            if (dist[next] > dist[here] + nextcost) {
                // 저장된 dist[next]보다  현재 점을 거쳐서 갈 경우가 거리가 더 짧으면 갱신 후 큐에 삽입
                dist[next] = dist[here] + nextcost;
                qu.push({ -dist[next], next });  // 우선 순위 큐는 Max Heap 구조이므로 
                // 가장 작은 값이 가장 큰 값이 되게 "-"를 곱해서 큐에 넣고 뺀다.
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF)
            cout << "INF" << "\n";
        else
            cout << dist[i] << "\n";
    }

    return 0;
}
