#include <iostream>

using namespace std;

int arr[3000][3000];
int a1,a2,a3;
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
        if(arr[s.y][s.x]==-1) a1++;
        if(arr[s.y][s.x]==0) a2++;
        if(arr[s.y][s.x]==1) a3++;
        return;
    }
    int sum=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            dfs({s.x + j*(len/3),s.y + i*(len/3)},len/3);
        }
    }
    
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    dfs({0,0},n);
    cout<<a1<<'\n'<<a2<<'\n'<<a3<<'\n';
    
    return 0;
}
