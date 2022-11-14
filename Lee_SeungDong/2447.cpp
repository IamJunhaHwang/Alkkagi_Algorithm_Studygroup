#include <iostream>
using namespace std;

char star[2187][2187];

void copy(int s) {
    int s_s = s/3;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            //가운데 빈칸 만들기
            if(i==1 && j==1){
                for(int k=0; k<s_s; k++){
                    for(int l=0; l<s_s; l++){
                        star[k+s_s][l+s_s] = ' ';
                    }
                }
            }
            //왼쪽 위 부분을 가운데 부분을 제외하고 나머지 7부분에 복사
            else {
                for(int k=0; k<s_s; k++){
                    for(int l=0; l<s_s; l++){
                        star[k+s_s][l] = star[k][l];
                        star[k+(2*s_s)][l] = star[k][l];
                        star[k][l+s_s] = star[k][l];
                        star[k+(2*s_s)][l+s_s] = star[k][l];
                        star[k][l+(2*s_s)] = star[k][l];
                        star[k+s_s][l+(2*s_s)] = star[k][l];
                        star[k+(2*s_s)][l+(2*s_s)] = star[k][l];
                    }
                }
            }
        }
    }
}

void fractal(int s) {
    //가장 작은 값 3
    if(s==3) return;
    //크기를 3으로 나누면서 재귀
    fractal(s/3);
    copy(s);
}

//2차원 배열 출력
void print_2D(int s) {
    for(int i= 0; i<s; i++){
        for(int j=0; j<s; j++) cout << star[i][j];
        cout << endl;
    }
}

int main() {
    int N;
    cin >> N;

    //초기 배열 설정
    star[0][0] = '*'; star[0][1] = '*'; star[0][2] = '*';
    star[1][0] = '*'; star[1][1] = ' '; star[1][2] = '*';
    star[2][0] = '*'; star[2][1] = '*'; star[2][2] = '*';

    fractal(N);

    print_2D(N);
}