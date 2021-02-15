#include <iostream>
#include<vector>
using namespace std;
long long arr[1030][1030];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,x1,x2,y1,y2;
    cin>>n>>m;
    for(int i =1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cin>>arr[i][j];
            arr[i][j]+=arr[i][j-1];
        }
    }
    for(int i = 0;i<m;i++){
         cin>>x1>>y1>>x2>>y2;
         long long ans = 0;
         for(int j=x1;j<=x2;j++){
             ans+=(arr[j][y2]-arr[j][y1-1]);
         }
         cout<<ans<<'\n';
    }
   
    return 0;
}
