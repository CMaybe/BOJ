#include<iostream>
#include<cstring>
#include<deque>
#include<queue>
#include<algorithm>
using namespace std;

typedef struct NODE{
	int x;
	int y;
	int t;
}Node;

bool check[101][101];
int arr[101][101];

int dx[4] = { 0,0,+1,-1};
int dy[4] = {+1,-1,0,0};



int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	
	int n;
	int a,b;
	cin >> n;
	
	for(int i =1;i<=n;i++){
		for(int j =1;j<=n;j++){
			cin>>arr[i][j];
		}
	}
	int id = 1;
	for(int i =1;i<=n;i++){
		for(int j =1;j<=n;j++){
			if(arr[i][j]==1&& check[i][j]==false){
				queue<Node> q;
				id++;
				arr[i][j]=id;
				q.push({j,i,0});
				while(!q.empty()){
					Node c = q.front();
					check[c.y][c.x] = true;
					q.pop();
					arr[c.y][c.x] = id;
					for(int k = 0;k<4;k++){
						int nx = c.x + dx[k];
						int ny = c.y + dy[k];
						if(nx>=1 && nx<=n && ny<= n && ny>=1 && arr[ny][nx]==1 && check[ny][nx]==false){
							check[ny][nx] = true;
							q.push({nx,ny,0});
						}
					}
				}
			}
		}
	}
	int ans = 1e9;
	memset(check,false,sizeof(check));
	id = 0;
	for(int i =1;i<=n;i++){
		for(int j =1;j<=n;j++){
			if(arr[i][j]>0 && (id!=arr[i][j])){
				memset(check,false,sizeof(check));
				deque<Node> dq;
				dq.push_back({j,i,0});
				id = arr[i][j];
				while(!dq.empty()){
					Node c = dq.front();
					dq.pop_front();
					check[c.y][c.x] = true;
					if(arr[c.y][c.x] != id && arr[c.y][c.x] > 0){
						ans = min(ans,c.t-1);
					}
					for(int k = 0;k<4;k++){
						int nx = c.x + dx[k];
						int ny = c.y + dy[k];
						if(nx>=1 && nx<=n && ny<= n && ny>=1 && check[ny][nx] == false){
							check[ny][nx] = true;
							if(arr[ny][nx]==0) dq.push_back({nx,ny,c.t + 1});
							else if(arr[ny][nx]!=id) dq.push_front({nx,ny,c.t + 1});
							else dq.push_front({nx,ny,c.t});
						}
					}
				}
			}
		}
	}
	
	cout << ans;
	return 0;
	
}
