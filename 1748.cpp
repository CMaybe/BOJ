#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    long long n,ans=0;
    cin >> n;
    int i =1;
    long long t=n;
    if(n<10){
        cout<<n;
        return 0;
    }
    while(n){
        if(n/10!=0){
            ans+=(int)(pow(10,i) - pow(10,i-1)) * i;
            i++;
            n/=10;
            continue;
        }
        ans+= i*(t-pow(10,i-1)+1);
        n/=10;
    }
    cout<<ans;
    return 0;
}
