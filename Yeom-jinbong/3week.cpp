#include <iostream>
using namespace std;
int main()
{
	int num;
	int count = 0;
	int temp = 0;
	int count2 = 0;
	cin >> num;
	int* N = new int[num];
	for (int i = 0; i < num; i++) {
		cin >> N[i];
	}
	for (int i = 0; i < num; i++) {
		for (int j = 2; j <= N[i]; j++) {
			for (int k = 2; k <= j; k++) {
				if (j % k == 0) {
					if (j == k)break;
					count2++;
					break;
				}
				else if (N[i] % j != 0) {
					count2++;
					break;
				}
			}
			if (count2 == 0) {
				temp = N[i];
				while (1) {
					if (temp % j == 0) {
						temp = temp / j;
						count++;
					}
					else break;
				}
				if (count >= 1) {
					cout << j << " " << count << endl;
				}
				count = 0;
			}
			count2 = 0;
		}
	}
	delete[] N;
	return 0;
}

