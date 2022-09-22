#include<iostream>
using namespace std;

/**
    2*N칸 일때 경우의 수 a_n: 전칸이 00일 때 +3, 01,10일 때는 +2
    a_n칸의 00개수 = a_n-2
    -> a_n = 2*a_n-1 + a_n-2
**/

int main() {
    int N;
    int ans[100001];
    ans[1]=3;   ans[2]=7;
    cin >> N;

    for(int i=3; i<=N; i++) ans[i] = (2*ans[i-1] + ans[i-2])%9901;
    
    cout << ans[N];
    return 0;
}