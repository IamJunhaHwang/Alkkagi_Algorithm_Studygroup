#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>

using namespace std;

int n, x, y, z;
int parent[100001];

vector<tuple<int, int, int>> P;
vector<pair<int, int>> X;
vector<pair<int, int>> Y;
vector<pair<int, int>> Z;

int find_Parent(int child) {
	
	// 연결된 노드가 없으면 그대로 반환
	if (parent[child] == child) return child;
	// 아니면 최초의 노드까지 찾아감
	else return parent[child] = find_Parent(parent[child]);

}

bool check_cycle(int u, int v) {
	
	u = find_Parent(u);
	v = find_Parent(v);

	// 두 노드의 부모가 같으면 이미 연결되있는거라 false 반환
	// 부모가 다르면 연결해주고, true 반환
	if (u != v) {
		parent[u] = v;
		return true;
	}
	else return false;

}

int main() {

	cin >> n;

	// 자기 자신이 부모로 초기화
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < n; i++) {
		cin >> x >> y >> z;
		// x,y,z 좌표중 하나만 비교해서 제일 작은 값을 넣어주면 되므로
		// 좌표와 노드번호를 묶어서 넣어준다.
		X.push_back(make_pair(x, i));
		Y.push_back(make_pair(y, i));
		Z.push_back(make_pair(z, i));
	}

	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	sort(Z.begin(), Z.end());

	for (int i = 0; i < n-1; i++) {
		// 노드의 거리가 작은 순으로 노드의 번호와 함께 넣어준다.
		P.push_back(make_tuple(X[i + 1].first - X[i].first, X[i + 1].second, X[i].second));
		P.push_back(make_tuple(Y[i + 1].first - Y[i].first, Y[i + 1].second, Y[i].second));
		P.push_back(make_tuple(Z[i + 1].first - Z[i].first, Z[i + 1].second, Z[i].second));
	}

	// x,y,z 좌표 전체적으로 정렬해줌
	sort(P.begin(), P.end());

	int answer = 0;

	for (int i = 0; i < P.size(); i++) {
		// 두 노드의 번호와 그 사이의 비용을 받아옴.
		int cost = get<0>(P[i]);
		int u = get<1>(P[i]);
		int v = get<2>(P[i]);

		// 만약 이미 연결된 노드가 아니라면 연결해주고, 비용을 더해준다.
		if (check_cycle(u, v)) answer += cost;
	}

	cout << answer;
	return 0;
}