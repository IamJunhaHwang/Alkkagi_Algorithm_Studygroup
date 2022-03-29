#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	
	int n;

	cin >> n;

	vector<int> arr;

	int score;
	int my;
	cin >> my;

	for (int i = 0; i < n-1; i++) {
		cin >> score;
		arr.push_back(score);
	}

	int cnt = 0;
	
	while (n!=1){
		sort(arr.begin(), arr.end(), greater<>()); // sorting
		if (my > arr[0]) break;
		cnt++;
		my++;
		arr[0]--;
		/*for (int i = 0; i < n - 1; i++) {
			cout << arr[i] << "/";
		}
		cout << "my : " << my;
		cout << endl;*/
	}

	cout << cnt;

	return 0;
}