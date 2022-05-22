#include <iostream>
#include <math.h>

using namespace std;

double x, y, c, h1, h2;
double low, high, res;

double cal(double w) {				// c를 구하는 식. (비례식을 사용해서 정리함)
	h1 = sqrt(x * x - w * w);		
	h2 = sqrt(y * y - w * w);		// 피타고라스 정리를 통해 구함

	return (h1 * h2) / (h1 + h2);	// guess_c
}



int main() {

	cin >> x >> y >> c;

	low = 0;
	high = min(x, y);		// high, low ==> 이분 탐색 범위.
	res = 0;

	while (high - low > 0.001) {			// 0.001의 오차까지 허용.
		double w = (low + high) / 2.0;		
		double guess_c = cal(w);

		if (guess_c >= c) {		// 입력받은 c보다 계산한 값이 더 크므로 w는 이보다 커야 함.
			res = w;
			low = w;
		}
		else			// 입력받은 c보다 계산한 값이 더 작으므로 w는 이보다 작아야 함.
			high = w;
	}
	
	printf("%.3f \n", res);

	return 0;

}