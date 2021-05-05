#include <iostream>
#include<algorithm>
using namespace std;

char arr[51][51];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            scanf(" %1c",&arr[i][j]);
        }
    }
    
    int ans = 1;
    bool flag = true;
    
    for(int ty = 1;ty<=n-1;ty++){
        for(int tx = 1;tx<=n;tx++){
            if(arr[ty][tx]!=arr[ty+1][tx]){
                swap(arr[ty][tx],arr[ty+1][tx]);
                flag= true;
            }
            for(int i = 1;i<=n;i++){
                char c = arr[i][1];
                int cnt = 1;
                for(int j = 2;j<=n;j++){
                    if(c==arr[i][j]){
                        cnt++;
                        if(ans<cnt)ans= cnt;
                    }
                    else{
                        c=arr[i][j];
                        cnt=1;
                    }
                }
                
            }
            
            for(int i = 1;i<=n;i++){
                char c = arr[1][i];
                int cnt = 1;
                for(int j = 2;j<=n;j++){
                    if(c==arr[j][i]){
                        cnt++;
                        if(ans<cnt)ans= cnt;
                    }
                    else{
                        c=arr[j][i];
                        cnt=1;
                    }
                }
            }
            
            if(flag){
                swap(arr[ty][tx],arr[ty+1][tx]);
                flag= false;
            }
        }
    }
    
    for(int ty = 1;ty<=n;ty++){
        for(int tx = 1;tx<=n-1;tx++){
            if(arr[ty][tx]!=arr[ty][tx+1]){
                swap(arr[ty][tx],arr[ty][tx+1]);
                flag=true;
            }
            for(int i = 1;i<=n;i++){
                char c = arr[i][1];
                int cnt = 1;
                for(int j = 2;j<=n;j++){
                    if(c==arr[i][j]){
                        cnt++;
                        if(ans<cnt)ans= cnt;
                    }
                    else{
                        c=arr[i][j];
                        cnt=1;
                    }
                }
            }
            
            for(int i = 1;i<=n;i++){
                char c = arr[1][i];
                int cnt = 1;
                for(int j = 2;j<=n;j++){
                    if(c==arr[j][i]){
                        cnt++;
                        if(ans<cnt)ans= cnt;
                    }
                    else{
                        c=arr[j][i];
                        cnt=1;
                    }
                }
            }
            if(flag){
                swap(arr[ty][tx],arr[ty][tx+1]);
                flag = false;
            }
        }
    }
    printf("%d",ans);
}
