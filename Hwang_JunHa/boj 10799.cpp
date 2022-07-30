# include <iostream>
# include <string>

using namespace std;

char bar[100000];
int top = 0;
string b;
int res = 0;


// bar 부분은 필요없지만 이해하기 쉽게 스택으로 구현.

int main() {					
	cin >> b;

	for (int i = 0; i < b.size(); i++) {
		if (b[i] == '(' && b[i+1] == ')') {		// 레이저가 나올 때 마다 나온 막대기가 잘리므로 스택에 저장해둔 막대기 수를 더함.
			res += top;
			i++;
		}

		else if(b[i]=='(')		// 막대기일 경우 스택에 저장
			bar[top++] = '(';

		else {					// 막대기의 잘려나가고 마지막 끝부분을 ++ 해주어야 함.
			bar[top - 1] = ' ';
			top--;
			res++;
		}
	}
	
	cout << res << endl;

	return 0;
}