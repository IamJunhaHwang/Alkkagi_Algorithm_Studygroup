# include <iostream>

using namespace std;

int N;
int check = 2;
int cntw = 0;
int cntb = 0;
int wcheck = 0;
int bcheck = 0;
int arr[128][128];
int visit[128][128];


int main() {					

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	check = N;


	// check를 계속 2로 나누어 주면서 영역을 나눈다고 생각하면 됨.

	while (check != 0) {		
		for (int z = N-1; z >= 0; z -= check) {			// 29,30번째 줄은 영역을 넘어가게 해주는 window size를 결정하는 부분.		[ sliding window ]
			for (int x = N-1; x >= 0; x -= check) {
				for (int i = z; i > z - check; i--) {  // 31, 32번째 줄은 정사각형 영역을 확인하는 부분.
					for (int j = x; j > x - check; j--) {
						if (visit[i][j] == 1)
							break;

						//cout << i << " \t" << j << endl;
						if (arr[i][j] == 1)		// 해당 칸이 어떤 색으로 채워졌는지 count 하는 부분
							bcheck++;
						else
							wcheck++;
					}
				}
				//cout << cntw << endl << cntb << endl;
				if (bcheck == (check * check)) {			// 영역이 모두 특정 색깔로 채워져있다면, 해당 영역을 확인하지 않아도 되므로 visit을 이용해 break되게 한다.
					cntb++;
					for (int i = z; i > z - check; i--)
						for (int j = x; j > x - check; j--)
							visit[i][j] = 1;
				}
				else if (wcheck == (check * check)) {
					for (int i = z; i > z - check; i--)
						for (int j = x; j > x - check; j--)
							visit[i][j] = 1;
					cntw++;
				}
				bcheck = 0;
				wcheck = 0;
			}
		}
		check /= 2;
	}

		cout << cntw << endl << cntb << endl;

	return 0;
}