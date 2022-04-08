# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

int main() {
	int N, num;  // 컴퓨터 수, 쌍 개수
	int pair[1000][2];  // 컴퓨터 쌍 저장
	int flag = 1;
	vector <int> virus;  // virus가 걸린 컴퓨터 번호 저장
	
	
	cin >> N >> num;

	for (int i = 0; i < num; i++) {  // 연결쌍 입력
		cin >> pair[i][0] >> pair[i][1];
	}

	for (int i = 0; i < num; i++) {  // 1번 컴퓨터가 바이러스의 시작이므로 1번 컴퓨터와 연결된 컴퓨터 모두 검색 후 저장
		if (pair[i][0] == 1 && find(virus.begin(), virus.end(), pair[i][1]) == virus.end())
			virus.push_back(pair[i][1]);

		else if (pair[i][1] == 1 && find(virus.begin(), virus.end(), pair[i][0]) == virus.end())
			virus.push_back(pair[i][0]);
	}

	if (virus.begin() == virus.end()) {  // 1번 컴퓨터가 안나오면 바이러스에 안걸리므로 0개
		cout << 0 << endl;
		return 0;
	}

	while (flag) {  // 바이러스에 걸린 컴퓨터를 찾으면 반복, 다 찾으면 끝. (flag의 역할)
		flag = 0;
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < virus.size(); j++) {  // 바이러스에 걸린 컴퓨터를 기록해 놓은 벡터에 해당되고, 기록이 안되어 있다면 기록한다.
				if (pair[i][0] == virus[j] && find(virus.begin(), virus.end(), pair[i][1]) == virus.end()) {  
					virus.push_back(pair[i][1]);
					flag = 1;
				}

				else if (pair[i][1] == virus[j] && find(virus.begin(), virus.end(), pair[i][0]) == virus.end()) {
					virus.push_back(pair[i][0]);
					flag = 1;
				}
			}
		}
	}

		cout << virus.size() - 1 << endl;  // 바이러스에 걸린 컴퓨터의 개수, 1번 컴퓨터를 통해 걸린 컴퓨터의 개수이므로 1을 빼준다.

	return 0;
}