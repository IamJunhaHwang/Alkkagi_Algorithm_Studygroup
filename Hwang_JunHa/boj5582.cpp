#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>


using namespace std;

string t, s;

int arr[4001][4001];
int maxlen = 0;

int main() {

    cin >> t >> s;

    for (int i = 0; i < t.length(); i++) {
        for (int j = 0; j < s.length(); j++) {
            if (t[i] == s[j]) {  // 같은 문자가 나오면 이전 위치에서의 공통 부분 값 + 1
                arr[i + 1][j + 1] = arr[i][j] + 1;
                maxlen = max(maxlen, arr[i + 1][j + 1]);
            }
        }
    }

    cout << maxlen << endl;
    
    

    return 0;
}
