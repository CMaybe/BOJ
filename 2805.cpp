#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
long long arr[1000001];
int main()
{
    long long n,m;
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    long long _min,_max,ans=0;
    _min=0;
    _max=arr[n-1];
    long long mid=0;
    while(_min<=_max){
        mid= (_min+_max)/2;
        long long sum=0;
        for(int i = 0;i<n;i++){
            long long t = arr[i]-mid;
            if(t<0) t= 0;
            sum+=t;
        }
        if(sum < m){
            _max=mid-1;
        }
        else{
            if(mid >ans)
                ans=mid;
            _min=mid+1;
        }
    }
    cout<<ans;
    return 0;
}
