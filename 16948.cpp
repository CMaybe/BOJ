#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdlib>
#include<algorithm>
using namespace std;


typedef struct POINT{
	int r;
	int c;
}Point;

int arr[202][202];
	
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	
	queue<Point> q;
	int n,sr,sc,gr,gc;
	cin>> n;
	cin>>sr>>sc>>gr>>gc;
	q.push({sr,sc});
	memset(arr,-1,sizeof(arr));
	arr[sr][sc]=0;

	while(q.empty()==false){
		Point p = q.front();
		q.pop();
		if(p.r==gr && p.c==gc){
			break;
		}
		if(p.r - 2 >= 0 && p.c-1 >= 0 && (arr[p.r-2][p.c-1] == -1)){
			arr[p.r-2][p.c-1] = arr[p.r][p.c] +1;
			q.push({p.r-2,p.c-1});
		}
		if(p.r - 2 >= 0 && p.c+1 < n && (arr[p.r-2][p.c+1] == -1)){
			arr[p.r-2][p.c+1] = arr[p.r][p.c] +1;
			q.push({p.r-2,p.c+1});
		}
		if(p.c - 2 >= 0 && (arr[p.r][p.c-2] == -1)){
			arr[p.r][p.c-2] = arr[p.r][p.c] +1;
			q.push({p.r,p.c-2});
		}
		if(p.c + 2 < n && (arr[p.r][p.c+2] == -1)){
			arr[p.r][p.c+2] = arr[p.r][p.c] +1;
			q.push({p.r,p.c+2});
		}
		if(p.r + 2 < n && p.c - 1 >= 0 && (arr[p.r + 2][p.c - 1] == -1)){
			arr[p.r+2][p.c-1] = arr[p.r][p.c] +1;
			q.push({p.r+2,p.c-1});
		}
		if(p.r + 2 < n && p.c + 1 < n && (arr[p.r + 2][p.c + 1] == -1)){
			arr[p.r+2][p.c+1] = arr[p.r][p.c] +1;
			q.push({p.r+2,p.c+1});
		}
	}
	cout<< arr[gr][gc];
	
	return 0;
	
}
