#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main() {
	stack<char> S;
	string str;
	int cnt = 0;

	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			S.push(str[i]);
		}
		else if (str[i] == ')' and str[i - 1] == '(') {
			S.pop();
			cnt += S.size();
		}
		else {
			cnt++;
			S.pop();
		}
	}

	cout << cnt;
}