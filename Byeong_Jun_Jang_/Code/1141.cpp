#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std; // 1141
int main() { // 받을 문자열을 벡터에 저장 후에 정렬함 이후에 
	int n; // 접두사는 크기가 작기때문 비교함
	cin >> n;
	vector<string> a(n);
	vector<string>::iterator it;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	/*	for (int i = 0; i < n; i++) { // 정렬 후 출력 시엔
	cout << a[i] << ' '; // h hello hi return run running 순으로 출력
	//	cout << a.size();
	//a.erase();
	}*/			// 이후엔 배열 바로 뒤와 비교 후 삭제 할지 안할지
	int c = a.size();
	for (int i = 0; i < a.size(); i++) { 
		// 비교 알고리즘
										 /*	a[i].substr(0, a.size());	//
										 int c = a.size(); //string s;
										 for (int j = 0; j < a.size(); j++) {
										 it = find(a.begin(), a.end(), a[j]);
										 if (it == a[j]) {
										 break;
										 }
										 }*/
		it = find(a.begin(), a.end(), a[i]);
		if (it != a.end()) {
			//a.erase(a.begin() + i);
		//	a.pop_back();
			a[i].pop_back();
			--c;
		}
		//		if (c==0) {
		/*			if (find(a.begin(), a.end(), 0) == a.end()){
		find(a.begin(), a.end(), a[i]);
		a[i].erase();
		c++;
		a[i].erase();
		a[i].substr(i, a.size());
		a.erase(a.begin() + i);
		c++;
		}
		a[i].erase();
		//		a[i].substr(0, a.size());
		}
		else if (c==2) {
		break;
		}
		cout << "okk" << endl;*/
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	//	cout << a.size();
	cout << c;
}