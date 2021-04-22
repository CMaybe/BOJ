#include <iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

int arr[10][10];
int arr2[10][10];
int visit[10][10];

int dx[] = {1,-1,0,0};
int dy[] = {0, 0, 1, -1};


typedef struct POINT{
    int x;
    int y;
}Point;

int n,m;
queue<Point> q;
vector<Point> v;
vector<int> mask;
vector<Point> w;


int bfs(){
    while(!q.empty()){
        Point p = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = p.x+dx[i];
            int ny = p.y+dy[i];
            if(nx>=1 && nx<=m && ny<=n && ny>=1){
                if(arr2[ny][nx]==0){
                    arr2[ny][nx]=2;
                    q.push({nx,ny});
                }
            }
        }
    }
    
    int cnt=0;
    for(int i = 1;i<=n;i++){
        for(int j =1;j<=m;j++){
            if(arr2[i][j]==0)cnt++;
        }
    }
    
    return cnt;
    
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    
    int ans=-1;
    cin>>n>>m;
    for(int i =1;i<=n;i++){
        for(int j =1;j<=m;j++){
            cin>>arr[i][j];
            if(arr[i][j]==0) w.push_back({j,i});
            if(arr[i][j]==2) v.push_back({j,i});
        }
    }
    
    for(int i = 0;i<w.size()-3;i++){
        mask.push_back(0);
    }
    
    for(int i = 0;i<3;i++){
        mask.push_back(1);
    }
    
    do{
        memset(visit,0,sizeof(visit));
        for(int i = 1;i<=n;i++){
            for(int j =1;j<=m;j++){
                arr2[i][j]=arr[i][j];
            }
        }
    
        
        for(int i =0;i<w.size();i++){
            if(mask[i]==1){
                arr2[w[i].y][w[i].x]=1;
            }
        }
        for(int i =0;i<v.size();i++){
            q.push(v[i]);
        }
        int t = bfs();
        if(t>ans) ans= t;
        
    }while(next_permutation(mask.begin(),mask.end()));
    
    
    cout<<ans;
    return 0;
}
