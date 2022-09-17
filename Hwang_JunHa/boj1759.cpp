#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int L, C;
char mo[5] = { 'a', 'e', 'i', 'o', 'u' };  // ������ �ּ� 1��, ������ �ּ� 2���� ���� ��. �̸� üũ�� �ֱ� ���� ���� ��Ʈ
char alpha[16];     
bool visit[16];
char res[16];
int chkmo;      // ���� ���� üũ.

void combi(int cnt, int check) {    // cnt: ��ȣ�� ���� ���ĺ� ��, check: ���ĵ� ���ڿ� ��ȣ�� ����� ���� ������. (������ ���� �� �ش� ���������� ���ĺ��� ��ȸ�ϰ� ����)
    if (cnt >= L) {
        chkmo = 0;

        for (int j = 0; j < 5; j++) {
            for (int i = 0; i < L; i++)
                if (res[i] == mo[j]) chkmo++;       // ������ �� �� ���� üũ
        }

        if (chkmo < 1 || L-chkmo < 2) return;   // ������� ��ȣ�� ������ ���ų� ������ 2�� �̸��̸� ��ȣ ���ǿ� ��߳�.

        for (int i = 0; i < L; i++)
            cout << res[i];

        cout << endl;

        return;
    }

    for (int i = check; i < C; i++) {  // a c i s t w
        if (visit[i] == false) {
            visit[i] = true;

            res[cnt] = alpha[i];

            combi(cnt + 1, i);      // ��ȣ�� ����� ���� ���ĺ��� ������;  ���� ���ĺ����� ������ ���� ���� ��ȣ�� �� �� ���� ���� ���� i �ε����� check�� �Ѱ���.
            visit[i] = false;
        }
    }
}

int main() {
    cin >> L >> C;

    for (int i = 0; i < C; i++)
        cin >> alpha[i];

    sort(alpha, alpha + C);     // �Է����� ���� ���ĺ��� �����Ѵ�.

    combi(0, 0);
    

    return 0;
}