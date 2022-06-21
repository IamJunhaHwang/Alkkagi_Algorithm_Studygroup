#include<iostream>
using namespace std;

int main() {
	int n, cnt = 0, max, key, flag = 0;
	int arr[50];
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	if (n == 1) {
		cnt = 0;
	}
	else {
		while (1) {
			for (int i = 1; i < n; i++) {
				if (arr[0] <= arr[i])
					flag = 1;
			}
			if (flag == 0)
				break;

			max = arr[1];
			key = 1;
			for (int i = 1; i < n; i++) {
				if (arr[i] > max) {
					max = arr[i];
					key = i;
				}
			}

			arr[key] -= 1;
			arr[0] += 1;
			cnt++;
			flag = 0;
		}
	}
	cout << cnt;

	return 0;
}
