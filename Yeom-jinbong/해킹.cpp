#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int n, m;
int cnt = 0; // 해킹 가능한 컴퓨터 갯수

vector<int> v[10001]; // 방향 그래프 설정
vector<int> ans;// 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터 번호를 저장
int maxx = -1; // 가장 많은 컴퓨터를 해킹 가능할 때 그 갯수
int visited[100001]; // 방문 체크

void dfs(int node) {

    visited[node] = 1;
    cnt++;

    for (int i = 0; i < v[node].size(); i++) {

        if (!visited[v[node][i]]) {
            dfs(v[node][i]);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }


    for (int i = 1; i <= n; i++) {

        cnt = 0;

        fill(visited, visited + n + 1, 0);
        dfs(i);


        // maxx 변수보다 cnt가 크면 maxx 초기화
        // ans 벡터 변수도 초기화
        if (maxx < cnt) {
            ans.clear();
            maxx = cnt;
            ans.push_back(i);

        }
        else if (maxx == cnt) {
            ans.push_back(i);
        }
    }

    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
/*#include<iostream>
using namespace std;
int N, M;
int A, B;
int arr1[10001][10001];
int arr2[10001];
int visited[10001][10001];
int sol(int index,int count) {
	for (int i = 1; i <= N;i++) {
		if (visited[i][index] != 1) {
			if (arr1[i][index] == 1) {
				count++;
				index = i;
				visited[i][index] == 1;
				sol(index, count);
			}
		}
	}
	return count;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			arr1[i][j] = 0;
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		arr1[A][B] = 1;
	}
	int index = 1;
	int count = 1;
	while (1) {
		if(index==5)break;
		arr2[index]=sol(index, count);
	}
	for (int i = 1; i <= N; i++) {
		cout << arr2[i] << ' ';
	}
	return 0;
}*/
