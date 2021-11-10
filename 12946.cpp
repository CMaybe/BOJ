#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[52][52];
int dx[6] = {0, 0, 1, -1,1,-1};
int dy[6] = {1, -1, 0, 0,-1,1};

bool ans[3];

typedef struct POINT{
    int x;
    int y;
}Point;

void func(int x, int y){
    
    if(arr[y][x]<4) return;
    vector<Point> v;
    bool colors[3] = {false,};
    for(int i = 0;i<6;i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(arr[ny][nx] > 0){
		    if(arr[ny][nx]<4) colors[arr[ny][nx]-1]=true;
		    else v.push_back({nx, ny});
		}
	}
	int cnt = 0;
	for(int i = 0;i<3;i++){
	    if(colors[i])cnt++;
	}
	int color = 1;
	if(cnt==0){}
	else if(cnt==1) color = (colors[0]==true ? 2: 1);
	else{
	    cout<<3;
	    exit(0);
	}
	arr[y][x]=color;
	ans[color-1]=true; 
	for(Point p : v){
	    func(p.x,p.y);
	}
    
}


int main()
{
	
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	vector<Point> v;
	int n;
	cin >> n;
	char t;
	for(int i = 0;i<=51;i++){
	    for(int j = 0;j<=51;j++){
	        arr[i][j]=-1;
	    }
	}
	for(int i = 1;i<=n;i++){
	    for(int j = 1;j<=n;j++){
	        cin>>t;
	        if(t=='X'){
	            arr[i][j] = 4;
	            v.push_back({j,i});
	        }
	    }
	}
	
	for(Point p : v){
	    func(p.x,p.y);
	}
	
	int cnt = 0;
	for(int i = 0;i<3;i++){
	    if(ans[i])cnt++;
	}
	cout <<cnt;
	return 0;
	
}
