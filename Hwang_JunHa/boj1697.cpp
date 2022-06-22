# include <iostream>
# include <queue>
# include <algorithm>

using namespace std;

int N, K;
int visit[100001];  // 밑의 코드에서 calc 변수를 위치 index로 사용하므로 1을 올려주어야 함.
int check= 0;
int pre_cnt = 0;	// 트리의 각 레벨
int cnt = 0;		// 최종 answer
int calc;			// 다음(1초 뒤) 위치 계산
int arr[3] = { -1, 1, 2 };	// 다음으로 갈 수 있는 위치
queue <pair<int,int>>q;

int main() {					

	cin >> N >> K;

	q.push({ N,0 });

	while (!q.empty()) {
		check = q.front().first;		// 큐에 저장된 값을 빼옴.
		pre_cnt = q.front().second;		// 큐에 다음 위치를 넣어줄 때 + 1 해주기 위해 가져옴.

		q.pop();

		if (check == K) {
			cnt = pre_cnt;
			break;
		}

		for (int i = 0; i < 3; i++) {
			if (arr[i] == 2) {
				calc = check * arr[i];

				if (calc < 0 || calc > 100000 || visit[calc] == 1)	// 이동 불가능한 위치이거나 이미 계산한 위치일 경우 pass
					;
				else {		// 갈 수 있는 위치라면 큐에 삽입.
					q.push({ calc, pre_cnt + 1 });
					visit[calc] = 1;
				}
			}
			else {
				calc = check + arr[i];
				if (calc < 0 || calc > 100000 || visit[calc] == 1)
					;
				else {
					q.push({ calc, pre_cnt + 1 });
					visit[calc] = 1;
				}
			}
		}
	}

	cout << cnt << endl;

	return 0;
}