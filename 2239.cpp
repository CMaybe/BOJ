#include<iostream>
#include<vector>
using namespace std;


int arr[10][10];
bool cols[10][10];
bool rows[10][10];
bool block[4][4][10];
bool finish = false;
int blank = 0;


typedef struct POINT{
    int x;
    int y;
}Point;

vector<Point> v;

Point make_point(int x, int y){
    Point p;
    p.x=x;
    p.y=y;
    return p;
}

bool game(int cnt){
    if(cnt==blank) return true;
    Point p = v[cnt];
    int x= p.x;
    int y = p.y;
    for(int n = 1;n<=9;n++){
        if(cols[x][n] || rows[y][n] || block[(y-1)/3+1][(x-1)/3+1][n]){}
        else{
            arr[y][x]=n;
            cols[x][n]=true;
	        rows[y][n]=true;
            block[(y-1)/3+1][(x-1)/3+1][n]=true;

            if(game(cnt+1))return true;        
            
            arr[y][x]=0;
            cols[x][n]=false;
	        rows[y][n]=false;
            block[(y-1)/3+1][(x-1)/3+1][n]=false;
        }
    }
    return false;
}

int main()
{
// 	cin.tie(0);
// 	cin.sync_with_stdio(false);
	for(int y = 1;y<=9;y++){
	    for(int x = 1;x<=9;x++){
	        scanf("%1d",&arr[y][x]);
	        
	        if(arr[y][x]==0){
	            v.push_back(make_point(x,y));
	            blank++;
	        }
	        else if(arr[y][x]>0){
	            cols[x][arr[y][x]]=true;
	            rows[y][arr[y][x]]=true;
	            block[(y-1)/3+1][(x-1)/3+1][arr[y][x]]=true;
	        }
	    }
	}
	game(0);
	for(int i = 1;i<=9;i++){
	    for(int j = 1;j<=9;j++){
	        cout<<arr[i][j];
	    }
	    cout<<'\n';
	}
	
}
