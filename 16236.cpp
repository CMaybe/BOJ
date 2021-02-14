#include <iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include <queue>
#include<cstring>
using namespace std;

int arr[22][22];
bool visit[22][22];
int dy[]={-1,0,0,1};
int dx[]={0,-1,1,0};

typedef struct POINT1{
    int x;
    int y;
    int time;
    int size;
    int ate;
}Shark;


typedef struct POINT2{
    int x;
    int y;
    int time;
}Point;


bool compare(Point a,Point b){
    if(a.time==b.time){
        if(a.y==b.y) return a.x<b.x;
        return a.y<b.y;
    }
    return a.time<b.time;
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    memset(arr,1000,sizeof(arr));
    
    int n;
    cin>>n;
    Shark shark;
    for(int i =1;i<=n;i++){
        for(int j =1;j<=n;j++){
            cin>>arr[i][j];
            if(arr[i][j]==9){
                shark.x=j;
                shark.y=i;
                shark.time=0;
                shark.size= 2;
                shark.ate=0;
            }
        }
    }
    int cnt = 0;
    int ans=0;
    arr[shark.y][shark.x]=0;
    while(true){
        vector<Point> fishes;
        //find fish
        for(int i = 1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(arr[i][j]<shark.size && arr[i][j]>0) fishes.push_back({j,i,9999999});
            }
        }
        if(fishes.size()==0) break;
        
        //select fish
        for(int i = 0;i<fishes.size();i++){
            int ty = fishes[i].y;
            int tx = fishes[i].x;
            queue<Point> q;
            q.push({shark.x,shark.y,shark.time});
            memset(visit,0,sizeof(visit));
            visit[shark.y][shark.x]=true;
            while(q.empty()==false){
                Point cur = q.front();
                q.pop();
                if(ty==cur.y && tx==cur.x){
                    fishes[i].time = cur.time;
                    break;
                }
                for(int i =0;i<4;i++){
                    int ny = cur.y+dy[i];
                    if(ny<=0 ||ny>n) continue;
                    int nx = cur.x+dx[i];
                    if(nx<=0 ||nx>n) continue;
                    if(arr[ny][nx] <= shark.size){
                        if(visit[ny][nx])continue;
                        visit[ny][nx]=true;
                        q.push({nx,ny,cur.time+1});
                    }
                }
            }
        }
        sort(fishes.begin(),fishes.end(),compare);
        
        Point target = fishes[0];
        if(target.time>=9999999)break;
        arr[target.y][target.x]=0;
        shark.x=target.x;
        shark.y=target.y;
        
        shark.time = target.time;
        shark.ate+=1;
        if(shark.ate==shark.size){
            shark.ate=0;
            shark.size++;
        }
    }
    if(shark.time>9999999)shark.time=0;
    cout<<shark.time;
    
    return 0;
}
