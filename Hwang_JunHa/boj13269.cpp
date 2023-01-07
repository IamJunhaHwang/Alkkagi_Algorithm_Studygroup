#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int N, M;

int tree[501][501];
int front[501];
int right_side[501];
int ans[501][501];
int maxr[501];
int maxf[501];
bool rflag = true;
bool fflag = true;

int main() {
    cin >> N >> M;  // N: 세로, M: 가로

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> tree[i][j];

    for (int i = 0; i < M; i++)  // 바라본 모양(0 ≤ 높이 ≤ 100) 이므로 존재하지 않는 경우를 이걸로 찾아야하는듯
        cin >> front[i];

    for (int i = 0; i < N; i++)
        cin >> right_side[i];

    /****** This is Front-side******/
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {  // check  N: 세로, M: 가로
            if (tree[i][j] != 0 && front[j] != 0) {  // 나무가 하나라도 있고 앞에서 볼때도 있었다면 정상 
                fflag = false;
            }
            if (tree[i][j] == 0)
                continue;
            else {
                ans[i][j] = front[j];
            }
        }
        if (fflag) { 
            cout << -1 << endl;
            return 0;
        }
    }

   /* for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }*/


    /****** This is right-side******/
    for (int i = 0; i <N; i++) {  // check  N: 세로, M: 가로
        for (int j = 0; j < M; j++) {
            if (tree[i][j] != 0 && right_side[N-1-i] != 0) {  // 나무가 하나라도 있고 오른편에도 나무가 있으면 정상
                rflag = false;
            }
            if (tree[i][j] == 0)
                continue;
            else if(ans[i][j] > right_side[N - 1 - i]){
                ans[i][j] = right_side[N - 1 - i];
            }
        }
        if (rflag) {
            cout << -1 << endl;
            return 0;
        }
    }

    /****** Check Validation*****
    위의 과정을 거쳐 나온 ans 배열이 초기에 주어졌던 앞에서 보았을 때 모양과 오른쪽에서 보았을 때 모양과 일치하는지 체크한다.
    */
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
            maxf[j] = max(maxf[j], ans[i][j]);
        }
        if (maxf[j] != front[j]) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i = 0; i < N; i++) {  // check  N: 세로, M: 가로
        for (int j = 0; j < M; j++) {
            maxr[i] = max(maxr[i], ans[i][j]);
        }
        if (maxr[i] != right_side[N - 1 - i]) {
            cout << -1 << endl;
            return 0;
        }
    }

    /****** Print Answer******/
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    

    return 0;
}
