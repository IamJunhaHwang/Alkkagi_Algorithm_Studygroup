#include <iostream>
#include <algorithm>

using namespace std;

int team1[15] = { 0,0,0,0,0,1,1,1,1,2,2,2,3,3,4 };
int team2[15] = { 1,2,3,4,5,2,3,4,5,3,4,5,4,5,5 };
int nara[6][3];
int exin[6][3];
int ans[4];

void combi(int res, int check) {
	if (check == 15) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				if (exin[i][j] != nara[i][j])
					return;
			}
		}

		ans[res] = 1;
		return;
	}

	int t1 = team1[check];
	int t2 = team2[check];

	nara[t1][0]++; nara[t2][2]++;	// t1 ½Â, t2 ÆÐ
	combi(res, check + 1);
	nara[t1][0]--; nara[t2][2]--;

	nara[t1][1]++; nara[t2][1]++;	// t1, t2 ¹«½ÂºÎ
	combi(res, check + 1);
	nara[t1][1]--; nara[t2][1]--;

	nara[t1][2]++; nara[t2][0]++;	// t1 ÆÐ t2 ½Â
	combi(res, check + 1);
	nara[t1][2]--; nara[t2][0]--;
}


int main() {
	int check = 0;

	for (int z = 0; z < 4; z++) {
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 3; j++)
				cin >> exin[i][j];

		combi(z, 0);

	}
	for (int i = 0; i < 4; i++)
		cout << ans[i] << " ";

	cout << endl;

	return 0;
}