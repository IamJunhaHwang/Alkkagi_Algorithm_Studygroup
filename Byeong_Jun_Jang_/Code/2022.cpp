#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
	double x, y, c;
	cin >> x >> y >> c; /* 
						d= d1+ d2		 d는 밑변 h는 높이
						h1=sqrt(x^2-d^2) 
						h2=sqrt(y^2-d^2)
						h:h1=d1:d / h:h2=d2:d => hd=h1d1 / hd=h2d2 => d1= hd/h1 / d2= hd/h2
						정리시 => h1h2/h2+h1
						*/
	double a = 0.0,b = min(x, y);
	double d, h, h1, h2;
	while (b-a>=0.00001) {
		d = (a+ b) / 2.0;
		h1 = sqrt(pow(x, 2) - pow(d, 2));
		h2 = sqrt(pow(y, 2) - pow(d, 2));
		h = h1 * h2 / (h2 + h1);
		if (h < c) {
			b = d;
		}
		else {
			a = d;
		}
//		cout << b << endl;
	}
	cout << b << endl;
}