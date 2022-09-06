#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int countW = 0;
int countB = 0;
int map[130][130];

void divCon(int ns, int ms, int ne, int me) {
	int check = map[ns][ms];

	for (int i = ns; i < ne; ++i) {
		for (int j = ms; j < me; ++j) {
			if (check == 0 && map[i][j] == 1) {
				check = 2;
			}
			else if (check == 1 && map[i][j] == 0) {
				check = 2;
			}
			if (check == 2) {
				divCon(ns, ms, (ns + ne) / 2, (ms + me) / 2);
				divCon((ns + ne) / 2, (ms + me) / 2, ne, me);
				divCon(ns, (ms + me) / 2, (ns + ne) / 2, me);
				divCon((ns + ne) / 2, ms, ne, (ms + me) / 2);
				return;
			}
		}
	}
	if (check == 0) {
		++countW;
	}
	else if (check == 1) {
		++countB;
	}
	return;
}

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	memset(map, 0, sizeof(map));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
		}
	}
	divCon(0, 0, n, n);

	cout << countW << endl;
	cout << countB << endl;
}