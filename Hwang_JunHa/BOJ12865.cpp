#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
int W, V;
int tmp;
int cnt = 0;
vector<pair<int, int>> items;
int dptable[101][100001];


int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> W >> V;
        items.push_back({ W, V });
    }

    for (int i = 1; i <= N; i++) {
        tmp = items[cnt].first;
        for (int j = 1; j <= K; j++) {
            if (j - tmp >= 0)
                dptable[i][j] = max(dptable[i - 1][j], dptable[i - 1][j - tmp] + items[cnt].second);
            else
                dptable[i][j] = dptable[i - 1][j];
        }
        cnt++;
    }

    cout << dptable[N][K] << endl;

    return 0;
}
