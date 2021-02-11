#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

char map[60][60];

char a[]={'W','B'};

int check(int sx,int sy,int idx){
    int sum=0;
    for(int i=sy;i<sy+8;i++){
        for(int j = sx;j<sx+8;j++){
            sum+=(int)(map[i][j]!=a[idx]);
            idx=!idx;
        }
        idx=!idx;
    }
    return sum;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i =1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            scanf(" %1c",&map[i][j]);
        }
    }
    int ans = 1e9;
    for(int i = 1;i<=n-7;i++){
        for(int j =1;j<=m-7;j++){
            int t = min(check(j,i,0),check(j,i,1));
            ans = min(ans,t);
        }
    }
    cout<<ans;
    
    return 0;
}
