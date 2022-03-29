#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<pair<int, int>> v;
	int count = 1;
	int count2 = 0;
	int start;
	int end;
	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		v.push_back(make_pair(end, start));
	}
	sort(v.begin(),v.end());
	for (int i = 1; i < N; i++) {
		if (v[count2].first <= v[i].second) {
			count++;
			count2 = i;
		}
	}
	cout << count << endl;
	return 0;
}
