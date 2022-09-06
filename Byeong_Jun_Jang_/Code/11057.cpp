#include <iostream>
using namespace std;
int main() {
	/*
오르막 수는 수의 자리가 오름차순을 이루는 수를 말한다. 이때, 인접한 수가 같아도 오름차순으로 친다.
예를 들어, 2234와 3678, 11119는 오르막 수이지만, 2232, 3676, 91111은 오르막 수가 아니다.
수의 길이 N이 주어졌을 때, 오르막 수의 개수를 구하는 프로그램을 작성하시오. 수는 0으로 시작할 수 있다
	*/
	int n;
	cin >> n;
	int arr[10001][10] = { 0, };
	int sum = 0;
/*	for (int i = 1; i <= 9; i++) {
		arr[]
	}*/
	for (int i = 1; i <= n; i++) {
//		arr[0][i] = 1;
		arr[i][0] = 1;
		for (int j = 1; j <= 9; j++) {
			arr[i][j] = (arr[i][j - 1] + arr[i - 1][j]) % 10007;
			
		}
		
	}
	for (int i = 0; i <= 9; i++) {
		sum += arr[n][i];
	}
	cout << sum % 10007;
/*length			n
	0	1	2	3	4	5	6	7	8	9
1	1	1	1	1	1	1	1	1	1	1
2	1	2	3	4	5	6	7	8	9	10	
3	1	3	6	10	15	21	28	36	45	55
4	1	4	10	20	35

	*/

}