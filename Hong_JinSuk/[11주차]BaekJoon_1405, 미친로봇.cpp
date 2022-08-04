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

	if (n == cnt) return 1.0; // �� �κ��� ���� ������.

	visited[x][y] = 1;

	double Prob = 0; // �� �κ��� �������� �ذ���ؼ� ��α� �����ؼ� ��� �ٲ�.

	for (int i = 0; i < 4; i++) {
		int next_x = x + m_x[i];
		int next_y = y + m_y[i];

		if (!visited[next_x][next_y]) {
			Prob += prob[i] * Search(next_x, next_y, cnt+1);
		} // ������ 1�̶�� Ȯ������ ���� ������ �ߴµ�, ���ϴ� ������� �ٲ�.
	}
	visited[x][y] = 0; // �۵��� ������ DFSó�� �ڷ� ����, �ִ� ���� �湮ǥ�� ����.
	                   // �̰� �����ָ�, �ٸ� ��ΰ� ��, �湮 ���ߴ� �͵� �湮�Ѱɷ� �ν�.
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