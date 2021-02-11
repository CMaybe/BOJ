#include <iostream>
#include<string>
#include<algorithm>
#include<functional>

long long arr[100001];
using namespace std;

int main() {
    long long k,n,ans;
    cin>>k>>n;
    for(int i = 0;i<k;i++){
        cin>>arr[i];
    }
    
    sort(arr,arr+k,greater<>());
    long long _min = 1;
    long long _max = arr[0];
    while(_min<=_max){
        long long m = (_min+_max)/2;
        
        long long cnt=0;
        for(int i=0;i<k;i++){
            cnt+=arr[i]/m;
        }
        if(cnt>=n){
            _min = m+1;
            ans=m;
        }
        else{
            _max=m-1;
        }
    }

    cout<<ans;
}
