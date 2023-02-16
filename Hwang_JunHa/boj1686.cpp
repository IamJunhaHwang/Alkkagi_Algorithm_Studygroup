# include <iostream>
# include <queue>
# include <algorithm>
# include <vector>
# include <math.h>
# pragma warning(disable:4996)


using namespace std;

int v, m;
double xs, ys, xt, yt, xb, yb;
bool visit[1001];

int cnt = 0;

queue<pair<int, pair<double, double>>> q;
vector<pair<double, double>> bunker;

double dist(double xa, double ya, double xb, double yb) {
	return pow((xa - xb), 2) + pow((ya - yb), 2);
}


int main() {
	cin >> v >> m;

	int lifetime = 60 * m * v;  // 닭이 움직일 수 있는 거리
	lifetime *= lifetime;

	cin >> xs >> ys;

	cin >> xt >> yt;

	while (cin >> xb >> yb) {  // EOF까지 입력 받기
		bunker.push_back({ xb, yb });
	}

	q.push({ 0,{ xs, ys } });

	while (!q.empty()) {
		cnt = q.front().first;
		xs = q.front().second.first;
		ys = q.front().second.second;
		q.pop();

		if (dist(xs, ys, xt, yt) < lifetime) {
			printf("Yes, visiting %d other holes. \n", cnt);
			return 0;
		}

		for (int i = 0; i < bunker.size(); i++) {
			double xb = bunker[i].first;
			double yb = bunker[i].second;

			if (dist(xs, ys, xb, yb) < lifetime && visit[i] == false) {
				visit[i] = true;
				q.push({ cnt + 1, { xb, yb } });
			}
		}
	}

	printf("No. \n");

	return 0;
}
