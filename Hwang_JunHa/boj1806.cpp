#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

int N, S;
int num[100000];    
int l, r;
int psum;  // 부분합
int length;

int main() {
    cin >> N >> S;


    for (int i = 0; i < N; i++) {
        cin >> num[i];
        
        if (num[i] >= S) {  // 길이가 1이고 S이상
            cout << 1 << endl;
            return 0;
        }
    }

    /*
       l
       ↓
     5 10 3 7 8 
            ↑
             r        psum = 20
    */


    l = 0;  // 왼쪽 경계
    r = 0;  // 오른쪽 경계
    length = N + 1;

    psum = num[l];

    while (l <= r && r < N) {
        if (psum < S) {  // 현재 길이만큼의 부분합 < S 면 오른쪽 경계 늘리기
            r++;
            psum += num[r];
        }
        else {  // 현재 길이 만큼의 부분합 >= S 면 길이 기록하고 왼쪽 경계를 앞으로 이동시켜서 반복
            length = min(length, r - l + 1);
            psum -= num[l];
            l++;
        }
    }

    // 아무리 더해도 S보다 작았으면 length를 0으로
    if (length == N + 1) length = 0;

    cout << length << endl;

    return 0;
}
