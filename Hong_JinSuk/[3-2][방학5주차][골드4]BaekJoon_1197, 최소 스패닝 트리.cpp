#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#define INF 987654321
using namespace std;

int v, e;
vector<tuple<int,int,int>> node;
int parent[10001];

bool compare(tuple<int,int,int> &Cost1, tuple<int,int,int> &Cost2) {
	return get<2>(Cost1) < get<2>(Cost2);
}

int find_Parent(int child) {
	// 아직 연결이 안된 노드면 그냥 반환
	if (parent[child] == child) return child;
	// 그게 아니면 최초의 노드까지 거슬러 올라감
	else return parent[child] = find_Parent(parent[child]);
}

bool check_Cycle(int start, int end) {

	start = find_Parent(start);
	end = find_Parent(end);

	// 최초의 연결 노드가 같으면 싸이클임
	if (start == end) return false;
	// 싸이클이 아니면 어디서 연결되는지 표시함.
	else {
		parent[end] = start;
		return true;
	}

}

int main() {

	cin >> v >> e;

	// node 들간 연결 완료
	for (int i = 0; i < e; i++) {

		int start, end, cost;
		cin >> start >> end >> cost;

		node.push_back(make_tuple(start, end, cost));

	}
	
	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}

	// cost 기준으로 오름차순으로 정렬
	sort(node.begin(), node.end(), compare);

	// node들 결합 
	int answer = 0;
	int count = 0;
	for (int i = 0; i < e; i++) {

		// 싸이클이 생기지 않으면 가중치를 더해준다.
		if (check_Cycle(get<0>(node[i]),get<1>(node[i]))) {
			answer += get<2>(node[i]);
			count++;
		}
		if (count == v - 1) break;

	}

	cout << answer;
	return 0;

}