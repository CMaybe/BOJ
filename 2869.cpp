#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
long long arr[1000001];
int main()
{
    long long v,a,b,sum=0;
    cin>>a>>b>>v;
    long long cnt =1;
    v-=a;
    long long ans = v/(a-b)+1;
    if(v%(a-b)>0)ans++;
    cout<<ans;
    return 0;
}
