#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n; //포도주 잔 개수
    cin >> n;

    int glass[10000] = {0, };
    for(int i=0; i<n; i++) {
        int amount; //잔에 들어있는 포도주 양
        cin >> amount;
        glass[i] = amount;
    }

    int wine_dp[10000] = {0, };
    wine_dp[0] = glass[0];
    wine_dp[1] = wine_dp[0] + glass[1];
    wine_dp[2] = max(wine_dp[0]+glass[2], max(wine_dp[1], glass[1]+glass[2]));
    // 초기값 설정

    for(int i=3; i<n; i++) {
        int temp_max = 0;
        temp_max = max(wine_dp[i-2]+glass[i], wine_dp[i-3]+glass[i-1]+glass[i]);
        wine_dp[i] = max(wine_dp[i-1], temp_max);
    } //bottom-up 방식 dp

    cout << wine_dp[n-1]; //출력

    return 0;
}