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
	
	// ����� ��尡 ������ �״�� ��ȯ
	if (parent[child] == child) return child;
	// �ƴϸ� ������ ������ ã�ư�
	else return parent[child] = find_Parent(parent[child]);

}

bool check_cycle(int u, int v) {
	
	u = find_Parent(u);
	v = find_Parent(v);

	// �� ����� �θ� ������ �̹� ������ִ°Ŷ� false ��ȯ
	// �θ� �ٸ��� �������ְ�, true ��ȯ
	if (u != v) {
		parent[u] = v;
		return true;
	}
	else return false;

}

int main() {

	cin >> n;

	// �ڱ� �ڽ��� �θ�� �ʱ�ȭ
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < n; i++) {
		cin >> x >> y >> z;
		// x,y,z ��ǥ�� �ϳ��� ���ؼ� ���� ���� ���� �־��ָ� �ǹǷ�
		// ��ǥ�� ����ȣ�� ��� �־��ش�.
		X.push_back(make_pair(x, i));
		Y.push_back(make_pair(y, i));
		Z.push_back(make_pair(z, i));
	}

	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	sort(Z.begin(), Z.end());

	for (int i = 0; i < n-1; i++) {
		// ����� �Ÿ��� ���� ������ ����� ��ȣ�� �Բ� �־��ش�.
		P.push_back(make_tuple(X[i + 1].first - X[i].first, X[i + 1].second, X[i].second));
		P.push_back(make_tuple(Y[i + 1].first - Y[i].first, Y[i + 1].second, Y[i].second));
		P.push_back(make_tuple(Z[i + 1].first - Z[i].first, Z[i + 1].second, Z[i].second));
	}

	// x,y,z ��ǥ ��ü������ ��������
	sort(P.begin(), P.end());

	int answer = 0;

	for (int i = 0; i < P.size(); i++) {
		// �� ����� ��ȣ�� �� ������ ����� �޾ƿ�.
		int cost = get<0>(P[i]);
		int u = get<1>(P[i]);
		int v = get<2>(P[i]);

		// ���� �̹� ����� ��尡 �ƴ϶�� �������ְ�, ����� �����ش�.
		if (check_cycle(u, v)) answer += cost;
	}

	cout << answer;
	return 0;
}