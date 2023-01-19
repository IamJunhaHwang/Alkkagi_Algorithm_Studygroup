#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int N, k;
	char x;
	cin >> k >> N;
	
	vector<char> num(N);
	vector<int> perm(N);
	for (int i = 0; i < N; i++) {
		cin >> x;
		num[i] = x;
	}
	sort(num.begin(), num.end());
	for (int i = 0; i < k; i++) {
		perm[i] = 1;
	}

	do {
		char temp[15] = { 0, };
		int idx = 0, cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < N; i++) {
			if (perm[i] == 1) {
				temp[idx] = num[i];
				idx++;
			}
		}
		for (int j = 0; j < idx; j++) {
			if (temp[j] == 'a' || temp[j] == 'e' || temp[j] == 'i' || temp[j] == 'o' || temp[j] == 'u') {
				cnt1++;
			}
			else {
				cnt2++;
			}
		}
		if (cnt1 > 0 && cnt2 > 1) {
			for (int z = 0; z < idx; z++) {
				cout << temp[z];
			}
			cout << endl;
		}
		
	} while (prev_permutation(perm.begin(), perm.end()));
	

	return 0;
}
