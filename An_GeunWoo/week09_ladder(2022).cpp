#include<iostream>
#include<math.h>
using namespace std;

double x, y;

double calc(double mid) {
	double h1 = sqrt(pow(x, 2) - pow(mid, 2));
	double h2 = sqrt(pow(y, 2) - pow(mid, 2));
	return (h1 * h2) / (h1 + h2);
}

int main() {
	double c;
	double res = 0;
	cin >> x >> y >> c;

	double high = min(x, y);
	double low = 0;

	while (high - low > 0.000001) {
		double mid = (high + low) / 2.0;
		double temp = calc(mid);

		if (temp >= c) {
			res = mid;
			low = mid;
		}
		else {
			high = mid;
		}
	}

	printf("%.3f", res);

	return 0;
}
