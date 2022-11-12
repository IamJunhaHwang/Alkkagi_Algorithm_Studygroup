#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

void star(int i, int j, int N) {
	if ((i / N) % 3 == 1 && (j / N) % 3 == 1)  // i / N: 반복되는 패턴을 만들기 위함.
		cout << " ";
	else {
		if (N / 3 == 0)
			cout << "*";
		else
			star(i, j, N / 3);
	}
}


int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			star(i, j, N);
		}
		cout << endl;
	}

	return 0;
}