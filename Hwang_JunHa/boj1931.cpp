# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

bool sorting(pair<int, int> p, pair<int, int>p2) {  // sort에 사용할 compare 함수 - 오름차순 sorting
	if (p.second == p2.second)  // 회의 종료 시간이 같으면 회의 시작 시간을 기준으로 sorting
		return p.first < p2.first;
	
	return p.second < p2.second;  // 기본적으로 회의 종료 시간을 기준으로 오름차순 sorting
	
}


int main() {
	int N, cnt = 1;
	int a, b;
	vector <pair<int, int>> v;
	int maxt;
	
	cin >> N;

	for (int i = 0; i < N; i++) {  // Input
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	sort(v.begin(), v.end(), sorting);  // 회의 종료 시간 기준 소팅
	 
	maxt = v[0].second;  // 회의 종료 시간이 가장 빠른 시간이 와야 최대가 되므로 vector의 첫 번째는 무조건 들어간다.

	for (int i = 1; i < N; i++) {
		if (v[i].first < maxt) {  // 선택한 회의와 겹치는 것을 필터링 해준다.
			continue;                                // 선택한 회의의 종료시간보다 빠르게 시작하는 것을 걸러주면 된다.
		}
		maxt = v[i].second;  // 위에서 걸러지지 않은 경우에는 해당 회의를 선택하게 되므로 max 회의 종료 시간을 갱신해준다.
		cnt++;
	}
	
	cout << cnt << endl;

	return 0;
}