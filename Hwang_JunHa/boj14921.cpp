#include <iostream>
#include <algorithm>
#include <math.h>
#include <climits>
#include <vector>

using namespace std;

int n, sol, tmp, ans;
int po[100001];
int ne[100001];
int pcnt = 0;
int ncnt = 0;
int res[100001];
int rcnt = 0;

vector<pair<int, int>> v;


int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> sol;

		if (sol < 0) {
			ne[ncnt++] = sol;

			v.push_back({ abs(sol), -1 });
		}
		else {
			po[pcnt++] = sol;

			v.push_back({ abs(sol), 1 });
		}

	}

	sort(v.begin(), v.end());


	if (ncnt == 0) {
		cout << po[0] + po[1] << endl;
		return 0;
	}
	else if (pcnt == 0) {
		cout << ne[ncnt-1] + ne[ncnt - 2] << endl;
		return 0;
	}
	else if (pcnt == 1 && ncnt == 1) {
		cout << ne[0] + po[0] << endl;
		return 0;
	}

	for (int i = 0; i < n-1; i++) {
		tmp = v[i].first * v[i].second + v[i + 1].first * v[i + 1].second;

		res[rcnt++] = tmp;
	}

	sort(res, res + rcnt);

	for (int i = 0; i < rcnt; i++) {
		if (res[i] > 0) {
			if (i == 0)
				ans = res[i];
			else if (abs(res[i - 1]) > res[i])
				ans = res[i];
			else
				ans = res[i - 1];

			break;
		}
	}

	cout << ans << endl;
	
	return 0;
}