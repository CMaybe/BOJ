#include <iostream>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

#define SIZE 32767

typedef struct POINT{
    int x;
    int y;
}Point;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int t;
    cin>>t;

    for(int i = 0;i<t;i++){  
        vector<Point> visit;
        vector<Point> v;
        queue<Point> q;
        int n;
        int px,py;
        int sx,sy;
        int ex,ey;
        cin>>n;
        cin>>sx>>sy;
        for(int j=0;j<n;j++){
            cin>>px>>py;
            v.push_back({px+SIZE,py+SIZE});
        }
        
        cin>>ex>>ey;
        v.push_back({ex+SIZE,ey+SIZE});
        q.push({sx+SIZE,sy+SIZE});
        visit.push_back({sx+SIZE,sy+SIZE});
        bool flag = false;
        while(q.empty()==false){
            Point p = q.front();
            q.pop();
            if(p.y==ey+SIZE && p.x==ex+SIZE){
                cout<<"happy\n";
                flag = true;
                break;
            }
            for(Point pp : v){
                bool isV=false;
                for(int k = 0;k<visit.size();k++){
                    if(visit[k].x==pp.x && visit[k].y==pp.y){
                        isV=true;
                        break;
                    }
                }
                if(isV) continue;
                int d = abs(p.x-pp.x)+abs(p.y-pp.y);
                if(d<=20*50){
                    visit.push_back(pp);
                    q.push({pp.x,pp.y});    
                }
                
            }
        }
        if(flag==false) cout<<"sad\n";
    }
    
    return 0;
}
