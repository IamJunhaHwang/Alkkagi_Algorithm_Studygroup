#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<pair<int, int>> v;
	int temp;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (temp < 0) {
			cnt++;  //어디까지가 음수인지 체크
		}
		v.push_back(pair<int, int>(abs(temp), i));
	}

	sort(v.begin(), v.end());  //부호 떼고 정렬

	for (int i = 0; i < N; i++) {
		if (v[i].second < cnt) {  //입력이 정렬된 상태이기 때문에 크기 비교만으로 가능
			v[i].first = v[i].first * -1;
		}
	}  //다시 부호 붙이기

	int arr[100010];
	for (int i = 0; i < N - 1; i++) {
		arr[i] = v[i].first + v[i + 1].first;
	}
	int arr2[100010];
	for (int i = 0; i < N - 1; i++) {
		arr2[i] = abs(arr[i]);
	}

	int min = arr2[0];
	int check = 0;
	for (int i = 1; i < N - 1; i++) {
		if (min > arr2[i]) {
			min = arr2[i];
			check = i;
		}
	}
	//차이값의 절댓값으로 크기 비교

	cout << arr[check] << endl;

	return 0;
}