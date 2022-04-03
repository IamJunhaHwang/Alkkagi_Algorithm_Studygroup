# include <iostream>
# include <string>
# include <algorithm>

using namespace std;

int main() {
	int N, cnt = 0;  
	string words[50];  // 50개의 단어 저장할 변수
	cin >> N;
	
	for (int i = 0; i < N; i++)
		cin >> words[i];

	sort(words,words+N);  // 알파벳순으로 정렬(시간복잡도를 줄이는 용도)
	                      // 예를 들어,  hi, h, hello면 정렬 후 h, hi, hello가 되므로 h가 바로 필터링 될 수 있다.

	for (int i = 0; i < N; i++) {  // 완전탐색
		for (int j = i+1; j < N; j++) {
			if (words[j].find(words[i]) == 0) {  // 접두사인 것이 확인되면
				words[i].clear();  // 접두사인 단어를 지운다.
				break;  // 비교대상이 지워졌으므로 더 이상의 반복은 무의미하다.
			}
		}
	}

	for (int i = 0; i < N; i++) {  // 지워진 단어를 빼고 카운트한다.
		if (words[i].empty())
			continue;
		else
			cnt++;
	}

	cout << cnt;
		

	return 0;
}