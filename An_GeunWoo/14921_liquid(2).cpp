#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[100010];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int temp = 200000005;
	int res = 0;
	int left = 0;
	int right = n - 1;
	while (left < right) {
		int sum = arr[left] + arr[right];
		if (abs(sum) < temp) {
			temp = abs(sum);
			res = sum;
		}
		if (sum == 0)
			break;
		else if (sum < 0)
			left++;
		else
			right--;
	}

	cout << res;

	return 0;
}