#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    int n,r,c;
    cin>>n>>r>>c;
    int ans=0;
    for(int i  =n;i>0;i--){
        int t;
        int s =(int)pow(2,i)/2;
        if(c<s&&r<s) t=0;
        else if(c>=s&&r<s) t=1;
        else if(c<s&&r>=s) t=2;
        else if(c>=s&&r>=s) t=3;
        
        c%=s;
        r%=s;
        ans+=(int)pow(s,2)*t;
    }
    cout<<ans;

    return 0;
}
