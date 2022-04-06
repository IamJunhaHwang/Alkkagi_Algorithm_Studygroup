#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	string arr[50];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int flag = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		flag = 0;
		for (int j = 0; j < n; j++) {
			if (i == j)
				continue;
			for (int k = 1; k <= arr[j].length(); k++) {
				if (arr[i] == arr[j].substr(0, k)) {
					flag = 1;
					arr[i] = " ";
					break;
				}
			}
			if (flag == 1)
				break;
		}
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] != " ")
			cnt++;
	}
	cout << cnt;

	return 0;
}