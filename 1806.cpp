
#include <iostream>

using namespace std;
int arr[1000001];
int main()
{
    long long int s = 0,sum=0;
    int n = 0,ans=20000000,len = 0;
    int st=0,e=0;
    cin >>n>>s;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
        sum+=arr[i];
        if(sum>=s){
            e = i;
            for(int j = st; sum-arr[j]>=s;j++){
                st = j + 1;
                sum-=arr[j];
            }
            len = e - st + 1;
            if(len < ans){
                ans = len;
                
            }
        }
    }
    if(ans == 20000000 ) ans = 0;
    cout << ans;
    return 0;
}
