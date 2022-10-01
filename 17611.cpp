#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



typedef struct POINT{
    int x;
    int y;
}Point;

vector<Point> v;

int n;
int X[1000002];
int Y[1000002];

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	cin >> n;
	
	for(int i = 0;i<n;i++){
	    int a,b;
	    cin >> a>>b;
	    v.push_back({a+500000,b+500000});
	}
	for(int i = 0;i<n;i++){
	    int x = v[i].x;
	    int y = v[i].y;
	    
	    int nx = v[(i+1)%n].x;
	    int ny = v[(i+1)%n].y;
	    
	    if(x == nx){
	        int y_max = max(y,ny);
	        int y_min = min(y,ny);
	        Y[y_min]++;
	        Y[y_max]--;
	    }
	    else{
	        int x_max = max(x,nx);
	        int x_min = min(x,nx);
	        X[x_min]++;
	        X[x_max]--;
	    }
	}
	int ans = 0;
	for(int i = 1;i<=1000001;i++){
	    X[i]+=X[i-1];
	    Y[i]+=Y[i-1];
	    ans = max(ans,max(X[i],Y[i]));
	}
	
	cout << ans;
	
}
