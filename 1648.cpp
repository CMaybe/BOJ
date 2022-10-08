#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct POINT{
    int u;
    int v;
    int w;
}Point;

vector<Point> points;
int parent[100001];
int N,M,ans,cnt;

int find(int idx){
    if(parent[idx] == idx) return idx;
    return parent[idx] = find(parent[idx]);
}

void Union(int x, int y, int w){
    int a = find(x);
    int b = find(y);
    
    if ( a == b ) return;
    parent[b] = a;
    ans += w;
    cnt++;
}



int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 1;i<=N;i++)parent[i]=i;
    int u, v, w;
    for(int i = 0;i<M;i++){
        cin >> u >> v >> w;
        points.push_back({u,v,w});
    }
    
    sort(points.begin(),points.end(),[](const Point& a,const Point& b){
        return a.w < b.w;
    });
    
    for(int i = 0;i<M;i++){
        int u = points[i].u;
        int v = points[i].v;
        int w = points[i].w;
        
        Union(u, v, w);
        if (cnt == N - 2) break;
    }
    
    cout << ans;
    
    return 0;
}
