#include <iostream>
using namespace std;
int arr[1001][11];
int main()
{
    int N;
    int result = 0;
    cin >> N;
    for (int i = 0; i <= 9; i++) {
        arr[1][i] = 1;
    }
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= j; k++) {
                arr[i][j] += arr[i - 1][k];
            }
            arr[i][j] %=10007;
        }
    }
    for (int i = 0; i <= 9; i++) {
        result += arr[N][i];
    }
    cout << result % 10007;
    return 0;
}
