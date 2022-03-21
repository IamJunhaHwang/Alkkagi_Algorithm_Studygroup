# include <iostream>
# include <algorithm>
# include <cmath>

using namespace std;

int main() {
	int a;
	int N[10000];
	int sosu[10000]; sosu[0] = 2;
	int flag = 0;
	int maxnum = -1;
	int cnt = 1;

	cin >> a;

	for (int i = 0; i < a; i++) {  // 입력 중에서 가장 큰 값을 찾아, 그 값까지의 소수를 구해 저장해 놓은 것임.
		cin >> N[i];
		maxnum = max(maxnum, N[i]);
	}

	for (int i = 3; i <= maxnum; i+=2) {  // 소수 구하기 - 입력의 최댓값까지의 소수를 구한다.
		for (int j = 3; j < int(sqrt(i)); j++) {
			if (i % j == 0) {  // 소수가 아님
				flag = 1;
				break;
			}
		}
		if (flag == 0) // 소수인 경우 배열에 저장한다.
			sosu[cnt++] = i;
		flag = 0;
	}

	for (int i = 0; i < a; i++) {  // 입력받은 수를 소인수 분해하기
		for (int j = 0; N[i] != 1; j++) {  // 입력받은 수가 1이 될 때까지 계속 소수로 나누어 준다.
			int count = 0;
			while(N[i] % sosu[j] == 0) {  // 소수로 입력받은 수를 나눌 수 있으면 나누어 준다.
				N[i] /= sosu[j];
				count++;  // 나눈 횟수 체크
			}
			if(count !=0)  // 해당 소수로 나누지 않았을 경우 (count가 0이면) 출력하지 않는다.
				cout << sosu[j] <<" " << count << endl;
		}
	}


	return 0;
}