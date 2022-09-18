#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int L, C;
vector<char> arr;
vector<char> Aeiou{ 'a','e','i','o','u' };
int Aeiou_check, Aeiou_check2;

void Input() {

	cin >> L >> C;

	int Check = 0;

	while (!Check) {

		Aeiou_check = 0;

		for (int i = 0; i < C; i++) {
			char c;
			cin >> c;
			arr.push_back(c);
		}

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < arr.size(); j++) {
				if (arr[j] == Aeiou[i]) Aeiou_check++; // ���� �ϳ��� üũ~
			}
		}

		if (Aeiou_check >= 1 && arr.size() - Aeiou_check >= 2) Check = 1; // ���� 1���̻� ���� 2���̻��̸� Pass

		else arr.clear(); // �ƴϸ� �ٽ� ����
	}
}

int main() {

	Input(); //���� 1���̻�, ����2���̻� �Է°���!!

	sort(arr.begin(), arr.end());

	vector<int> temp; // � ������ ���մϴ�!!
	for (int i = 0; i < L; i++) {
		temp.push_back(1);
	}
	for (int i = 0; i < C - L; i++) {
		temp.push_back(0);
	}

	vector<char> v;
	
	do {
		Aeiou_check2 = 0;

		for (int i = 0; i < arr.size(); i++) {
			if (temp[i] == 1) { 
				v.push_back(arr[i]);
			} // L����ŭ �̽��ϴ�!!
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < v.size(); j++) {
				if (v[j] == Aeiou[i]) Aeiou_check2++;
			} // �������� Check!!
		}
		if (Aeiou_check2 >= 1 && v.size() - Aeiou_check2 >= 2) {
			for (int i = 0; i < v.size(); i++) {
				cout << v[i];
			} // ���� 1���̻� && ���� 2���̻� �̸�, ���
			cout << endl;
		}
		v.clear();
	} while (prev_permutation(temp.begin(), temp.end()));
	// while�� �ڵ� ��ó : https://twpower.github.io/90-combination-by-using-next_permutation , https://mjmjmj98.tistory.com/38

	return 0;
}