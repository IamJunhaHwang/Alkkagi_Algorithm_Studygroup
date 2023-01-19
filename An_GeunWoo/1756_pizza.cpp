#include<iostream>
using namespace std;

int main() {
	int D, N;
	cin >> D >> N;
	int Darr[300010];
	int Narr[300010];

	for (int i = 1; i <= D; i++) {
		cin >> Darr[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> Narr[i];
	}

	for (int i = 2; i <= D; i++) {
		if (Darr[i] > Darr[i - 1])
			Darr[i] = Darr[i - 1];
	}

	int pivot = D + 1;
	int cnt = 1;
	for (int i = D; i >= 1; i--) {
		if (Darr[i] >= Narr[cnt]) {
			pivot = i;
			cnt++;
			if (cnt > N)
				break;
		}
		else {
			continue;
		}
	}

	if (cnt <= N)
		pivot = 0;

	cout << pivot;

	return 0;
}
