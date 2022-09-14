#include <iostream>
using namespace std;
int main(){
    while(true){
    int n;
    cin>>n;
    auto d = new int[n+1][3];
    //int d[n+1][3];
    d[1][0]=d[1][1]=d[1][2]=1;
    for(int i=2;i<=n;i++){
        d[i][0]=(d[i-1][0]+d[i-1][1]+d[i-1][2])%9901;
        d[i][1]=(d[i-1][0]+d[i-1][2])%9901;
        d[i][2]=(d[i-1][0]+d[i-1][1])%9901;
    }
    cout<<(d[n][0]+d[n][1]+d[n][2])%9901<<endl;
    /*cout<<d[1][0]<<endl;
    cout<<d[1][1]<<endl;
    cout<<d[1][2]<<endl;*/
    delete [] d;
    }
}
/*
|   |   |
|   |   |  
|   |   |
n = 1 3가지 \ n = 2 7가지 \ n = 3 17가지 \ n = 4 41가지
d[1][0]=d[1][1]=d[1][2]=1

d[i][0]=d[i-1][0]+d[i-1][1]+d[i-1][2]
d[i][1]=d[i-1][0]+d[i-1][2]
d[i][2]=d[i-1][0]+d[i-1][1]
*/