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
	// ���� ������ �ȵ� ���� �׳� ��ȯ
	if (parent[child] == child) return child;
	// �װ� �ƴϸ� ������ ������ �Ž��� �ö�
	else return parent[child] = find_Parent(parent[child]);
}

bool check_Cycle(int start, int end) {

	start = find_Parent(start);
	end = find_Parent(end);

	// ������ ���� ��尡 ������ ����Ŭ��
	if (start == end) return false;
	// ����Ŭ�� �ƴϸ� ��� ����Ǵ��� ǥ����.
	else {
		parent[end] = start;
		return true;
	}

}

int main() {

	cin >> v >> e;

	// node �鰣 ���� �Ϸ�
	for (int i = 0; i < e; i++) {

		int start, end, cost;
		cin >> start >> end >> cost;

		node.push_back(make_tuple(start, end, cost));

	}
	
	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}

	// cost �������� ������������ ����
	sort(node.begin(), node.end(), compare);

	// node�� ���� 
	int answer = 0;
	int count = 0;
	for (int i = 0; i < e; i++) {

		// ����Ŭ�� ������ ������ ����ġ�� �����ش�.
		if (check_Cycle(get<0>(node[i]),get<1>(node[i]))) {
			answer += get<2>(node[i]);
			count++;
		}
		if (count == v - 1) break;

	}

	cout << answer;
	return 0;

}