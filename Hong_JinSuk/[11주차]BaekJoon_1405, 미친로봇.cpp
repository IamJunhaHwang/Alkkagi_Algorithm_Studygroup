#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int n;
int visited[30][30] = { 0, };
int m_x[4] = { 1,-1,0,0 };
int m_y[4] = { 0,0,-1,1 };
double prob[4];

double Search(int x, int y, int cnt) {

	if (n == cnt) return 1.0; // 이 부분은 내가 놓쳤음.

	visited[x][y] = 1;

	double Prob = 0; // 이 부분은 내꺼에서 해결못해서 블로그 참고해서 방식 바꿈.

	for (int i = 0; i < 4; i++) {
		int next_x = x + m_x[i];
		int next_y = y + m_y[i];

		if (!visited[next_x][next_y]) {
			Prob += prob[i] * Search(next_x, next_y, cnt+1);
		} // 원래는 1이라는 확률에서 빼는 식으로 했는데, 더하는 방식으로 바꿈.
	}
	visited[x][y] = 0; // 작동이 끝나고 DFS처럼 뒤로 갈때, 있던 곳의 방문표시 삭제.
	                   // 이거 안해주면, 다른 길로갈 때, 방문 안했던 것도 방문한걸로 인식.
	return Prob;
}

int main() {

	cin >> n;
	for (int i = 0; i < 4; i++) {
		float a;
		cin >> a;
		prob[i] = a / 100;
	}

	double answer = Search(15, 15, 0);
	cout << fixed << answer;
	return 0;
}