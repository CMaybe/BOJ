#include <iostream>

using namespace std;

int arr[128][128];
typedef struct POINT{
    int x;
    int y;
}Point;

void dfs(Point s,int len){
    bool flag = true;
    for(int i = s.y;i<s.y+len;i++){
        for(int j=s.x;j<s.x+len;j++){
            if(arr[i][j]!=arr[s.y][s.x]){
                flag=false;
                break;
            }
        }
    }
    if(flag){
        printf("%d",arr[s.y][s.x]);
        return;
    }
    printf("(");
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            
            dfs({s.x + j*(len/2),s.y + i*(len/2)},len/2);
            
        }
    }
    printf(")");
    
}

int main()
{
    
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf(" %1d",&arr[i][j]);
        }
    }
    dfs({0,0},n);
    return 0;
}
