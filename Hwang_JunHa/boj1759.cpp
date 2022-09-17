#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int L, C;
char mo[5] = { 'a', 'e', 'i', 'o', 'u' };  // 모음이 최소 1개, 자음이 최소 2개가 들어가야 함. 이를 체크해 주기 위한 모음 세트
char alpha[16];     
bool visit[16];
char res[16];
int chkmo;      // 모음 갯수 체크.

void combi(int cnt, int check) {    // cnt: 암호로 넣은 알파벳 수, check: 정렬된 문자열 암호를 만들기 위한 기준점. (조합을 만들 때 해당 기준점부터 알파벳을 조회하게 만듦)
    if (cnt >= L) {
        chkmo = 0;

        for (int j = 0; j < 5; j++) {
            for (int i = 0; i < L; i++)
                if (res[i] == mo[j]) chkmo++;       // 모음이 몇 개 인지 체크
        }

        if (chkmo < 1 || L-chkmo < 2) return;   // 만들어진 암호에 모음이 없거나 자음이 2개 미만이면 암호 조건에 어긋남.

        for (int i = 0; i < L; i++)
            cout << res[i];

        cout << endl;

        return;
    }

    for (int i = check; i < C; i++) {  // a c i s t w
        if (visit[i] == false) {
            visit[i] = true;

            res[cnt] = alpha[i];

            combi(cnt + 1, i);      // 암호로 만들어 넣은 알파벳의 갯수와;  넣은 알파벳보다 순서가 낮은 것이 암호로 올 수 없게 현재 넣은 i 인덱스를 check로 넘겨줌.
            visit[i] = false;
        }
    }
}

int main() {
    cin >> L >> C;

    for (int i = 0; i < C; i++)
        cin >> alpha[i];

    sort(alpha, alpha + C);     // 입력으로 받은 알파벳을 정렬한다.

    combi(0, 0);
    

    return 0;
}