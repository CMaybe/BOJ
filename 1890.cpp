#include <iostream>

using namespace std;
long long arr[111][111];
long long dp[111][111];
int main()
{
    int n;
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
        }
    }
    dp[1][1]=1;
    for(int i = 1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(arr[i][j]*dp[i][j]==0)continue;
            int ny=i+arr[i][j];
            int nx=j+arr[i][j];
            dp[i][nx]+=dp[i][j];
            dp[ny][j]+=dp[i][j];
        }
    }
    cout<<dp[n][n];
    
    // for(int i = 1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<dp[i][j]<<'\t';
    //     }
    //     cout<<'\n';
    // }
    
    return 0;
}
