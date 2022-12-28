#include <iostream>
#include <string>

using namespace std;
int K, N;
string arr[50];
string noun[50];
bool is_teach[26] = { false, };
bool tmp;
string knew = "antic";
int readable = 0;
int max_read = 0;

void find_teach(int idx, int cnt) {
	if (cnt == K) {
		for (int i = 0; i < N; i++) {
			tmp = true;
			for (int j = 0; j < arr[i].length(); j++) {
				if (is_teach[arr[i][j] - 'a']==false) {
					tmp = false;
					break;
				}
			}
			if (tmp)
				readable++;
		}
		if (max_read < readable)
			max_read = readable;

		readable = 0;
		return;
	}

	for(int k=idx; k<26; k++){
		if (is_teach[k]==false) {
			is_teach[k] = true;
			find_teach(k + 1, cnt + 1);
			is_teach[k] = false;
		}
	}
}


int main() {
	cin >> N >> K;  // N: 단어 개수, K: 가르칠 글자 개수

	cin.ignore();

	is_teach[0] = true;		// a
	is_teach[2] = true;		// c
	is_teach[8] = true;		// i
	is_teach[13] = true;	// n
	is_teach[19] = true;    // t

	K -= 5;

	if (K < 0) {      // K가 0보다 작아지게 되면 아무것도 읽을 수 없다. (기본적으로 a, n, t, i ,c는 배워야 하므로)
		cout << 0 << endl;
		return 0;
	}
	else if (K == 21) {
		cout << N << endl;
		return 0;
	}

	for (int i = 0; i < N; i++) {  // 단어를 입력받는다. (a, n, t, i , c 는 무조건 들어가므로 이를 제외시키고 저장한다.)
		cin >> arr[i];

		arr[i] = arr[i].substr(4, arr[i].length() - 8);

		/*for (int j = 0; j < arr[i].length(); j++) {
			if (noun[i].find(arr[i][j]) == string::npos) {  // 중복 글자 입력 방지
				noun[i] += arr[i][j];
				combi += arr[i][j];
			}
		}*/
	}

	find_teach(1, 0);

	cout << max_read << endl;

	return 0;
}
