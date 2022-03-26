#include<iostream>
using namespace std;

int main() {
	int n, temp, num, key;
	int arr[100000];
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 100000; j++) {
			arr[j] = 0;
		}
		cin >> num;
		temp = num;
		for (int j = 2; j <= temp; j++) {
			if (temp == j) {
				key = temp;
			}
			if (temp % j == 0) {
				arr[j] += 1;
				temp = temp / j;
				j--;
			}
		}
		for (int j = 2; j <= key; j++) {
			if (arr[j] > 0) {
				cout << j << " " << arr[j] << endl;
			}
		}
	}

	return 0;
}