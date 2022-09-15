#include<iostream>

using namespace std;

int N;
int arr[100001][3];

int main() {

	cin >> N;


	arr[1][1] = 1; // [1][1]에 사자가 있는 경우
	arr[1][2] = 1; // [1][2]에 사자가 있는 경우
	arr[1][0] = 1; // 전칸에 아무것도 없는 경우

	for (int i = 2; i <= N; i++) {
		arr[i][0] = arr[i - 1][2] + arr[i - 1][1] + arr[i - 1][0]; // 이번칸 건너뛰는 경우
		arr[i][1] = arr[i - 1][2] + arr[i - 1][0]; // 전칸에 대각에 있거나 없는 경우
		arr[i][2] = arr[i - 1][1] + arr[i - 1][0]; // 전칸에 대각에 있거나 없는 경우 22

		arr[i][0] %= 9901;
		arr[i][1] %= 9901;
		arr[i][2] %= 9901; // 이거 안하면 오버플로우 나더라.. ㅠㅠ
	}

	cout << (arr[N][0] + arr[N][1] + arr[N][2]) % 9901;

	return 0;
}