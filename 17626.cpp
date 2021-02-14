#include <iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;



int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int dp[1000001];
    int n;
    cin>>n;
    dp[0]=0;
    dp[1]=1;
    memset(dp,9999999,sizeof(dp));
    for(int i =1;i<=1000;i++){
        dp[i*i]=1;
    }
    int _min = 1e9;
    for(int i = 2;i<=n;i++){

        for(int j =1;j*j<=i;j++){
            dp[i] = min(dp[i],dp[j*j]+dp[i-j*j]);
        }
    }
    cout<<dp[n];
  
    
    return 0;
}
