#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, k;
	int dp[101][100001] = { 0, };
	int w[101] = { 0, }, v[101] = { 0, };

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j - w[i] >= 0) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[n][k];

	return 0;
}

/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, k, w, v;
	cin >> n >> k;

	vector<pair<int, int>> p;
	for (int i = 0; i < n; i++) {
		cin >> w >> v;
		p.push_back(make_pair(-v, w));
	}

	sort(p.begin(), p.end());

	int res[101] = { 0, };
	for (int j = 0; j < n; j++) {
		int n_w = 0, n_v = 0;
		for (int i = j; i < n; i++) {
			n_w += p[i].second;
			if (n_w < k) {
				n_v += p[i].first;
				if (i == n - 1) {
					res[j] = n_v;
				}
			}
			else if (n_w == k) {
				n_v += p[i].first;
				res[j] = n_v;
				break;
			}
			else {
				n_w -= p[i].second;
				if (i == n - 1) {
					res[j] = n_v;
				}
				continue;
			}
		}
	}

	int min = res[0];
	for (int i = 0; i < n; i++) {
		if (min > res[i]) {
			min = res[i];
		}
	}
	cout << min * -1;

	return 0;
}
*/