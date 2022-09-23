/*
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool sor(string a,string b){
    return a<b;
}
int main(){
    auto a = new string;
    int l,c;
    cin>>l>>c;
    int le=c;
    if(a||e||i||o||u){
        
    }
    for(int i=1;i<=c;i++){
        cin>>a[i];
    }
    sort(a,a+le,sor);
    for(int i=1;i<=c;i++){
        cout<<a[i];

    }
    delete a;
}
*/

#include <iostream>
#include <algorithm>
using namespace std;
char a[16]; // input
char b[16]; // 
bool check[16];
int l,c;
char mo[5]={'a','e','i','o','u'};
bool check_mo(char c){ // 이걸로 체크하면 오류 뜸
    if(c=='a'|c=='e'|c=='i'|c=='o'|c=='u'){
        return true;
    }
    return false;
}
void cb(int num,int idx) {
    int cnt=0;
    if(num>=l){/*
    for(int i=0;i<l;i++){ 이걸로하면 오류 뜸
        if(check_mo(a[i])==true){
            cnt++;
        }
    }*/
    for(int j=0;j<5;j++){
        for(int i=0;i<l;i++){
            if(b[i]==mo[j]) cnt++;
        }
    }
    
    if(cnt<1||l-cnt<2){
        return;
    }
        for(int i=0;i<l;i++){
            cout<<b[i];   
        }
        cout<<"\n";
    
    return;
    }
    for(int i=idx;i<c;i++){
        if(check[i]==false){
            check[i]=true;
            b[num]=a[i];
            cb(num+1,i);
            check[i]=false;
        }
    }
}
int main(){
    cin>>l>>c;
    for(int i=0;i<c;i++){
        cin>>a[i];
    }
    sort(a,a+c);
    cb(0,0);
}