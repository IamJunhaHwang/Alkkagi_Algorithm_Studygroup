#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	
	int n;
	cin >> n; //case

	vector<int> arr; // case를 넣는 배열
	vector<int> sosu; // 소수가 있는 배열
	vector<int> count; // 인수의 갯수를 받을 배열
	vector<int> divsosu; // 인수를 받을 배열
	vector<int> sosu_copy; // sosu 벡터에 넣기전에 에라토스테네스의 체로 소수구하기
	int a;

	for (int i = 0; i < n; i++) {
		cin >> a;
		arr.push_back(a); // arr에 case를 넣어줌
	}

	int MAX = *max_element(arr.begin(), arr.end()); //배열에서 최댓값찾음. + 잘됌

	for (int i = 0; i <= MAX; i++) {
		sosu_copy.push_back(i);
	}//MAX 이하의 수를 넣어준다. + 잘됌

	for (int i = 2; i <= MAX; i++) { // 에라토스테네스체 + 잘됌
		if (sosu_copy[i] == 0) continue;
		for (int j = i + i; j <= MAX; j += i) {
			sosu_copy[j] = 0;
		}
	}

	for (int i = 0; i <= MAX; i++) {
		if (sosu_copy[i] != 0 && sosu_copy[i] != 1) sosu.push_back(sosu_copy[i]); //sosu에 Max이하 소수 넣어줌+잘됌
	}



	for (int i = 0; i < n; i++) { // 모든 case검사
		for (int j = 0; j < sosu.size(); j++) { // MAX 이하의 모든 소수로 나눠봄
			int cnt = 0; // 인수갯수 체크
			if (arr[i] == 1) break; // 소인수분해가 끝나면 break;
			while (arr[i] % sosu[j] == 0) { //소수로 나눠지면 그 소수가 인수
				arr[i] = arr[i] / sosu[j];
				cnt++; // 나눠지면 인수갯수 ++
			}
			if (cnt > 0) { // 인수면 넣어준다.
				divsosu.push_back(sosu[j]); // 50인경우 sosu[0]=2, sosu[1]=5
				count.push_back(cnt); // 50의 경우 count[0]=1,count[1]=2이 된다.
			}
		}
	}
	for (int j = 0; j < divsosu.size(); j++) { //인수 갯수만큼 출력
		cout << divsosu[j] << " " << count[j] << endl;
	}

	return 0;
}