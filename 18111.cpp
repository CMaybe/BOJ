#include <iostream>
#include<string>
#include<cmath>
using namespace std;
int arr[501][501];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n,m,b;
    int min=999,max=-999;
    cin>>n>>m>>b;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>arr[i][j];
            if(min>arr[i][j])min=arr[i][j];
            if(max<arr[i][j])max=arr[i][j];
        }
    }
    long long ans=1e9;
    long long time = 1e9;
    
    for(int h = min;h<=max;h++){
        int mCnt=0;
        int pCnt=0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                int t = arr[i][j]-h;
                if(t<0)mCnt-=t;
                else if(t>0)pCnt+=t;
            }
        }
        if(mCnt <= pCnt + b){
            long long t = mCnt+(2*pCnt);
            if(t<=time){
                time=t;
                ans=h;
            }
        }
    }
    
    cout<<time<<' '<<ans;
    
    return 0;
}
