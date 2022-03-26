#include <iostream> // 양의 정수 n을 소인수분해 결과
using namespace std;  // 2 6 8 24
int main() {
	int n; int m; int c; 
	cin >> n;
	if (n >= 2 && n <= 100000) {
		while (n--) {
			cin >> m;
			while (m != 1) {
				for (int i = 2; i <= m; i++) {
					c = 0; 
					while (m%i == 0) {
						m /= i; 
						c++; // 나머지 없을 때까지 카운트
					}
					if (c != 0) {
						cout << i << " " << c << endl;
					}
				}
			}
		}
	}
}