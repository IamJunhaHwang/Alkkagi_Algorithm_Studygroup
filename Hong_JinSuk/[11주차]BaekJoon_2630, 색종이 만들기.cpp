#include<iostream>

using namespace std;

int Sq[130][130];
int n, num;
int white = 0;
int blue = 0;

bool one_B, zero_W;

void Search(int size, int x, int y) {
	one_B = true;
	zero_W = true;
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (Sq[i][j] == 1) zero_W = false;
			if (Sq[i][j] == 0) one_B = false;
		}
	}
	if (zero_W) {
		white++;
	}
	else if (one_B) {
		blue++;
	}
	else {
	Search(size / 2, x, y); // I
	Search(size / 2, x + size / 2, y); // II
	Search(size / 2, x, y + size / 2); // III
	Search(size / 2, x + size / 2, y + size / 2); // IV
	}
}

int main() {

	
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> num;
			Sq[i][j] = num;
		}
	}

	Search(n, 1, 1);

	cout << white << endl << blue;

	return 0;
}