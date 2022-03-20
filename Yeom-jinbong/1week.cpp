#include <iostream>
using namespace std;
int main() {
	int num;
	int count = 0;
	cin >> num;
	int num2[50];
	for (int i = 0; i < num; i++) {
		cin >> num2[i];
	}
	if (num == 1) {
		cout << 0;
		return 0;
	}
	while (1) {
		int temp = 0;
		int temp2 = 0;
		for (int i = 1; i < num; i++) {
			temp = i;
			for (int j = i + 1; j < num; j++) {
				if (num2[temp] < num2[j]) temp = j;
			}
			temp2 = num2[i];
			num2[i] = num2[temp];
			num2[temp] = temp2;
		}
		if (num2[0] <= num2[1]) {
			count++;
			num2[0]++;
			num2[1]--;
		}
		for (int i = 1; i < num; i++) {
			if (num2[0] > num2[i]) {
				if (i == num - 1) {
					cout << count;
					return 0;
				}
			}
			else break;
		}
	}
}
