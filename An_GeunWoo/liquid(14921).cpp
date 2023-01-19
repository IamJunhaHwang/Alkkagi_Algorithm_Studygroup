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
			cnt++;  //�������� �������� üũ
		}
		v.push_back(pair<int, int>(abs(temp), i));
	}

	sort(v.begin(), v.end());  //��ȣ ���� ����

	for (int i = 0; i < N; i++) {
		if (v[i].second < cnt) {  //�Է��� ���ĵ� �����̱� ������ ũ�� �񱳸����� ����
			v[i].first = v[i].first * -1;
		}
	}  //�ٽ� ��ȣ ���̱�

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
	//���̰��� �������� ũ�� ��

	cout << arr[check] << endl;

	return 0;
}