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
				if (arr[j] == Aeiou[i]) Aeiou_check++; // 모음 하나당 체크~
			}
		}

		if (Aeiou_check >= 1 && arr.size() - Aeiou_check >= 2) Check = 1; // 모음 1개이상 자음 2개이상이면 Pass

		else arr.clear(); // 아니면 다시 쓰기
	}
}

int main() {

	Input(); //모음 1개이상, 자음2개이상만 입력가능!!

	sort(arr.begin(), arr.end());

	vector<int> temp; // 몇개 뽑을지 정합니다!!
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
			} // L개만큼 뽑습니다!!
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < v.size(); j++) {
				if (v[j] == Aeiou[i]) Aeiou_check2++;
			} // 모음개수 Check!!
		}
		if (Aeiou_check2 >= 1 && v.size() - Aeiou_check2 >= 2) {
			for (int i = 0; i < v.size(); i++) {
				cout << v[i];
			} // 모음 1개이상 && 자음 2개이상 이면, 출력
			cout << endl;
		}
		v.clear();
	} while (prev_permutation(temp.begin(), temp.end()));
	// while문 코드 출처 : https://twpower.github.io/90-combination-by-using-next_permutation , https://mjmjmj98.tistory.com/38

	return 0;
}