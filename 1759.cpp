#include <iostream>
#include<algorithm>
#include<string>
using namespace std;

int L,C;

char arr[20];
bool isMo(char a){
    return a=='a'||a=='e'||a=='i'||a=='o'||a=='u';
}
void func(string s,int idx,int a, int b){//a:자음 b: 모음
    
    if(s.length()==L){
        if (a>=2 && b>=1){
            cout<<s<<'\n';
            return;
        }
        return;
    }
    for(int i = 1;i+idx<C;i++){
        int k=0,t=0;//k:자음
        isMo(arr[idx+i]) ? t=1 : k=1;
        func(s+arr[idx+i],idx+i,a+k,b+t);
    }
}

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(0);
    cin >> L >>C;
    for(int i = 0;i<C;i++){
        cin >> arr[i];
    }
    sort(arr,arr+C);
    
    for(int i = 0;i<C-L+1;i++){
        int k=0,t=0;//k:자음
        isMo(arr[i]) ? t=1 : k=1;
        func(string(1,arr[i]),i,k,t);
    }
    
    return 0;
}
