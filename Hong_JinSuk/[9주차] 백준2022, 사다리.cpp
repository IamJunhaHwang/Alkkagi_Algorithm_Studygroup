#include<iostream>
#include<stdio.h>
#include<cmath>

using namespace std;

int main() {

	float x, y, c;
	cin >> x >> y >> c;

	float Left = 0;
	float Right = x;

	for (int i = 0; i < 1000; i++) { // 10^-3이 1000번 하라는 뜻??

		float k = (Left + Right) / 2; // 이진방법으로 오차 좁힐예정
		float X = sqrt(x * x - k * k);
		float Y = sqrt(y * y - k * k);

		if (-(X * c / Y) + X > c) Left = k; // f(두 교점의 x 좌표) = -(Xc)/Y+x = c , f(x)는 직선 x에 대한 방정식
		else Right = k;
	}

	printf("%.3f", Left);
	return 0;
}