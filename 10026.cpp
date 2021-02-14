#include <iostream>
#include<string>
#include<queue>
using namespace std;
char arr1[101][101];
char arr2[101][101];
bool visit[101][101];
bool visit2[101][101];

int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};


typedef struct POINT{
    int x;
    int y;
}Point;
int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(0);
    
    int n;
    cin>>n;
    for(int i =1;i<=n;i++){
        for(int j =1;j<=n;j++){
            scanf(" %1c",&arr1[i][j]);
            arr2[i][j]=arr1[i][j];
            if(arr2[i][j]=='G') arr2[i][j]='R';
        }
    }
    
    int cnt=0;
    for(int i =1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(visit[i][j])continue;
            visit[i][j]=true;
            queue<Point> q;
            q.push({j,i});
            while(q.empty()==false){
                Point p = q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int nx=p.x+dx[k];
                    int ny=p.y+dy[k];
                    if(visit[ny][nx])continue;
                    if(arr1[ny][nx]==arr1[p.y][p.x]){
                        visit[ny][nx]=true;
                        q.push({nx,ny});
                    }
                }
                
            }
            cnt++;
        }
    }
    
    cout<<cnt<<' ';
    cnt=0;
    
    for(int i =1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(visit2[i][j])continue;
            visit2[i][j]=true;
            queue<Point> q;
            q.push({j,i});
            while(q.empty()==false){
                Point p = q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int nx=p.x+dx[k];
                    int ny=p.y+dy[k];
                    if(visit2[ny][nx])continue;
                    if(arr2[ny][nx]==arr2[p.y][p.x]){
                        visit2[ny][nx]=true;
                        q.push({nx,ny});
                    }
                }
                
            }
            cnt++;
        }
    }
    
    cout<<cnt;
    
    
    return 0;
}
