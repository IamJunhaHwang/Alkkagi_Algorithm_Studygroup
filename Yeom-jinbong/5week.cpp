#include <iostream>
using namespace std;
int main()
{
	int N;
	int count = 0;
	cin >> N;
	int num = N;
	string temp;
	string* word = new string[N];
	for (int i = 0; i < N; i++) {
		cin >> word[i];
	}
	for (int i = N; i >=0; i--) {
		for (int j = 1; j < i; j++) {
			if (word[j-1].size() > word[j].size()) {
				temp = word[j-1];
				word[j-1] = word[j];
				word[j] = temp;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			temp = word[j];
			if (word[j]== temp.replace(0, word[i].size(), word[i])) {
				count++;
			}
		}
		if (count > 0) {
			num--;
		}
		count = 0;
	}
	cout << num;
	return 0;
	delete[] word;
}
