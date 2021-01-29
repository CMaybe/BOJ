#include <iostream>

using namespace std;
long long arr[2003];
int dp[2003][2003];//[100001];
int main()
{
    int n;
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(0);
    bool flag = false;
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
        dp[i][i]=1;
        if(arr[i]==arr[i-1]){
                dp[i-1][i]=1;
            }
    }
    for(int i = 1;i<=n;i++){ //len
        for(int j = 1;j<=n;j++){
            if(arr[j]==arr[j+i-1]){
                if(dp[j+1][i+j-2]==1){
                    dp[j][i+j-1]=1;     
                }
            }
        }
    }
    int s,e;

    cin >>n;
    for(int i = 0;i<n;i++){
        cin>>s>>e;
        cout<<dp[s][e]<<'\n';
    }
    
    
    
    return 0;
}
