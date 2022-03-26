#include <iostream>
using namespace std;
int main() {
	int n; // n 설탕 킬로 b 봉지
	int b;
	b = 0;
	cin >> n;
	if (n > 2) {
		while (n > 0) {
			if (n % 5 == 0) {
				n -= 5;
				b++;
			}
			else {
				b++;
				n -= 3;
			}
			if (n < 0) {
				b = -1;
				break;
			}
		}
		cout << b << endl;
	}
}