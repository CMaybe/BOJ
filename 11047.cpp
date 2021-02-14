#include <iostream>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int n,k;
    cin>>n>>k;
    int arr[11];
    for(int i =n-1;i>=0;i--){
        cin>>arr[i];
    }
    int sum=0;
    int cnt=0;
    for(int i = 0;i<n;i++){
        while(sum+arr[i]<=k){
            sum+=arr[i];
            cnt++;
        }
        if(sum==k){
            cout<<cnt;
            break;
        }
    }
    
    return 0;
}
