#include <iostream>
#include<string>

using namespace std;

int main() {
    int n,cnt=0;
    cin>>n;
    int i=0;
    int temp;
    while(cnt!=n){
        int temp = i;
        bool flag = true;
        while(temp&&flag){
            if(temp%1000==666) flag = false;
            temp/=10;
        }
        
        if(!flag){
            cnt+=1;
        }
        i++;
    }
    cout<<i-1;
}
