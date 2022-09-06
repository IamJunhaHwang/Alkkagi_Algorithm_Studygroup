#include <iostream>
#include <queue>
using namespace std;
int n, k;
queue<int> que;
int visit[100001];
int path = 0;
int BFS() {
//	path[n] = 0;
	que.push(n);
	visit[n] = 1;
//	cout << "dd\n";
	while (!que.empty()) {
		int a = que.front();
		que.pop();
//		cout << "aa\n";
		if (a == k) return visit[a] - 1;
		if (a - 1 >= 0 && visit[a - 1] == 0) {
			que.push(a - 1);
			visit[a - 1] = visit[a] + 1;
		}
		if (a + 1 <= 100000 && visit[a + 1] == 0) {
			que.push(a + 1);
			visit[a + 1] = visit[a] + 1;
		}
		if (a * 2 <= 100000 && visit[2 * a]==0) {
			que.push(a * 2);
			visit[a * 2] = visit[a] + 1;
		}
		
//		cout << a <<" ";
//		path++;
	}
//	cout << path << endl;
//	cout << n << endl;
//	cout << &visit << endl;
	/*
	que.push(n);
	visit[n] = true;
	while (!que.empty()) {
		int x = que.front();
		que.pop();
		cout << x << " ";
	}
	*/
}
int main() {
	cin >> n >> k;
	cout<<BFS();
}