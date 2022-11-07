#include <iostream>
#include <algorithm>
using namespace std;

//내림차순 정렬
bool compare(int a, int b){
    return b < a;
}

int library(int n, int m, int book[]){
    int sum = 0;

    //음수 영역과 양수 영역을 구분
    int bookn[50] = {0,};
    int nindex = 0;
    int bookp[50] = {0,};
    int pindex = 0;
    for(int i=0;i<n;i++){ 
        if(book[i]<0) {
            bookn[nindex] = book[i];
            nindex++;
        }
        else{
            bookp[pindex] = book[i];
            pindex++;
        }
    }

    //음수는 오름차순, 양수는 내림차순 정렬
    sort(bookn, bookn+nindex);
    sort(bookp, bookp+pindex, compare);

    //각 영역 별로 걸음 수 세기
    if((bookn[0]*(-1)) < bookp[0]){
        for(int i=0;i<nindex;i+=m){
            int ntemp = bookn[i]*(-1)*2;
            sum += ntemp;
        }
        for(int i=m;i<pindex;i+=m){
            int ptemp = bookp[i]*2;
            sum += ptemp;
        }
        sum += bookp[0];
    }
    else{
        for(int i=m;i<nindex;i+=m){
            int ntemp = bookn[i]*(-1)*2;
            sum += ntemp;
        }
        for(int i=0;i<pindex;i+=m){
            int ptemp = bookp[i]*2;
            sum += ptemp;
        }
        sum += bookn[0]*(-1);
    }

    return sum;
}

int main() {
    int N, M;
    int bookc[50] = {0,};
    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> bookc[i];
    }

    int result = library(N, M, bookc);
    cout << result << endl;

    return 0;
}