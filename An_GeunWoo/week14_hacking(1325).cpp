#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int> graph[10001];
vector<int> visited;
vector<int> cnt;

int max_value = 0;

void dfs(int node) {
	cnt[node]++;
	max_value = max(max_value, cnt[node]);

	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (visited[next] == 0) {
			visited[next]++;
			dfs(next);
		}
	}
}

int main() {
	cin >> n >> m;

	int A, B;
	for (int i = 0; i < m; i++) {
		cin >> A >> B;
		graph[A].push_back(B);
	}

	cnt = vector<int>(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		visited = vector<int>(n + 1, 0);
		visited[i]++;
		dfs(i);
	}

	for (int i = 1; i <= n; i++) {
		if (cnt[i] == max_value) {
			cout << i << " ";
		}
	}

	return 0;
}


/*메모리 초과
#include<iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int A, B;
	int chk[100][100] = { 0, };
	for (int i = 0; i < m; i++) {
		cin >> A >> B;
		chk[A][B] = 1;
	}

	//테이블 확인
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << chk[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (chk[i][j] == 1) {
				int shift = i;
				for (int k = 1; k <= n; k++) {
					if (chk[k][shift] == 1) {
						chk[k][j] = 1;
					}
				}
			}
		}
	}

	//테이블 확인
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << chk[i][j] << " ";
		}
		cout << endl;
	}

	int res[100] = { 0, };
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (chk[j][i] == 1) {
				cnt++;
			}
		}
		res[i] = cnt;
	}

	int max = res[0];
	for (int i = 1; i <= n; i++) {
		if (max < res[i]) {
			max = res[i];
		}
	}
	for (int i = 1; i <= n; i++) {
		if (res[i] == max) {
			cout << i << " ";
		}
	}

	return 0;
}
*/