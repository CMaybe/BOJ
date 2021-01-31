#include <iostream>
#include<queue>
#include<cstring>
#include<cstdlib>
#include<vector>
using namespace std;
int arr[302][302];
int visit[302][302];

typedef struct POINT{
    int x;
    int y;
    int cnt;
}Point;
int dx[] = { 1, 1, 2,  2,-1, -1, -2, -2};
int dy[] = { 2,-2, 1, -1, 2, -2,  1, -1};
int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(0);
    int n,m;
    
    cin>>n;
    for(int i =1;i<=n;i++){
        int l;
        cin>>l;
        Point s,g;
        s.cnt= 0;
        g.cnt = 0;
        cin>>s.y>>s.x;
        cin>>g.y>>g.x;
        memset(arr,0,sizeof(arr));
        memset(visit,0,sizeof(visit));
        queue<Point> q;
        q.push(s);

        while(q.empty()==false){
            Point p = q.front();
            q.pop();
            visit[p.y][p.x]=1;
            if(p.x==g.x && p.y==g.y){
                cout<<p.cnt<<'\n';
                break;
            }
            for(int i =0;i<8;i++){
                int nx= p.x+dx[i];
                int ny= p.y+dy[i];
                if(nx>=0 &&ny>=0 && nx<l && ny<l){
                    if(visit[ny][nx]==1)continue;
                    visit[ny][nx]=1;
                    q.push({nx,ny,p.cnt+1});
                }
            }
        }
    }
    

    return 0;
}
