#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	int temp;
	int arr[60] = { 0, };
	for (int i = 0; i < N; i++) {
		cin >> temp;
		arr[i] = temp;
	}

	sort(arr, arr + N);

	int pivot = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i] < 0) {
			pivot++;
		}
	}

	int res = 0;
	for (int i = 0; i < pivot; i += M) {
		res += abs(arr[i]) * 2;
	}
	for (int i = N - 1; i >= pivot; i -= M) {
		res += arr[i] * 2;
	}
	res -= max(abs(arr[0]), arr[N - 1]);

	cout << res;

	return 0;
}