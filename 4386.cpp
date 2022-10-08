#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

typedef struct POINT{
    double x;
    double y;
}Point;

typedef struct NODE{
    double w;
    int a;
    int b;
}Node;

vector<Point> points;
vector<Node> nodes;
int parent[100001];
int N,cnt = 0;
double ans = 0;

int find(int idx){
    if(parent[idx] < 0) return idx;
    return parent[idx] = find(parent[idx]);
}

bool Union(int x, int y){
    int a = find(x);
    int b = find(y);
    
    if ( a == b ) return false;
    parent[b] = a;
    return true;
}

double dist(Point a,Point b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0;i<=N;i++) parent[i] = -1;
    for(int i = 0;i<N;i++){
        double a,b;
        cin >> a >> b;
        points.push_back({a,b});
    }
    
    for(int i = 0;i<N;i++){
        for(int j = 0;j<i;j++){
            nodes.push_back({dist(points[i],points[j]),i,j});
        }
    }
    
    sort(nodes.begin(),nodes.end(),[](const Node& a,const Node& b){
        return a.w < b.w;
    });
    
    for(int i = 0;i<nodes.size();i++){
        int a = nodes[i].a;
        int b = nodes[i].b;
        double d = nodes[i].w;
        if(Union(a,b)){
            ans += d;
            cnt++; 
            if(cnt == N - 1) break;
        }
    }
    cout << fixed << setprecision(2) << ans;
    
    return 0;
}
