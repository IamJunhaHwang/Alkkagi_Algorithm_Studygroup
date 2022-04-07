#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n = 0;

bool compare(pair<string, int> a, pair<string, int> b) {
	if (a.second > b.second) {
		return a.second < b.second;
	}
	if (a.second == b.second) {
		return false;
	}
}

int main() {

	cin >> n;

	string a;
	int b;
	vector<pair<string,int>> str; // 글자 + 글자길이

	for (int i = 0; i < n; i++) {
		cin >> a;
		b = a.size();
		str.push_back({ a,b });
	}

	sort(str.begin(), str.end(), compare); // 길이가 짧은 순번으로 정렬ok

	for (int i = 0; i < str.size(); i++)
		cout << str[i].first << ' ' << str[i].second << endl;

	int cnt = 0;
	
	for (int i = 0; i < n; i++) {
		
		if (str[i].second != -1) { // 이미 다른 집합에 들어간 원소는 제외
			
			str[i].second = -1; // 집합에 들어감. 1:a.second=-1
			string L_str = str[i].first; // 1:L_str=a,
			int len = str[i].first.size(); 
			
			for (int j = 0; j < n; j++) { // i에 해당하는 원소에 대해 나머지 모든 원소 비교
				len = L_str.size();
				if (L_str == str[j].first) str[j].second = -1; // 중복되는 원소는 제외 j=2: ab -1
				if (str[j].second != -1 && L_str == str[j].first.substr(0, len)) {
					L_str = str[j].first; // str.first가 L_str를 포함하므로 교체
					str[j].second = -1; // 같은 집합에 들어왔으므로 제외
				}
			}
			
			cnt++; //집합의 갯수 세줌
		}
	}

	cout << cnt;

	return 0;
}
