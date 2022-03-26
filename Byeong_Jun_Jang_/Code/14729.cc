#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n;
	int m[100];
	int a; a = 0;
	int c; c = 0;
	int d;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m[i];
	}
	for (int i = 0; i < n; i++) {
		if (m[i] > m[a]) {
			a = i;
		}
		if (a == 0 && m[i] == m[a]) {
			a = i;
		}
	}
	for (int i = 0; i < n; i++) {
		if (m[i] == m[a]) {
			c++;
		}
	}
	d = 0;
	while (a != 0 || c > 1) {
		d++;
		m[a]--;
		m[0]++;
		a = 0;
		c = 0;
		for (int i = 0; i < n; i++) {
			if (m[i] > m[a]) {
				a = i;
			}
			if (a == 0 && m[i] == m[a]) {
				a = i;
			}
		}
		for (int i = 0; i < n; i++) {
			if (m[i] == m[a]) {
				c++;
			}
		}
	}
	cout << d << endl;
}