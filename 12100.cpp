#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
 
int n;
int ans;
int map[23][23];

enum DIR{
	RIGHT,
	LEFT,
	UP,
	DOWN
};

typedef struct POINT{
	int x;
	int y;
}Point;

void dfs(int idx, int cnt){
	if(cnt == 5){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				ans = max(map[i][j],ans);
			}
		}
		return;
	}
	bool visit[23][23] = {false,};
	if(idx == RIGHT){
		for(int i = 1;i<=n;i++){
			for(int j = n -1 ;j>=1;j--){
				if (map[i][j] == 0) continue;
				int k;
				for(k = j+1; k<=n; k++){
					if(map[i][k]!=0) break;
					map[i][k] = map[i][k-1];
					map[i][k-1] = 0;
				}
				k--;
				if (map[i][k] == map[i][k+1] && visit[i][k+1] == false){
					map[i][k] = 0;
					map[i][k+1] *= 2;
					int d;
					for(d = k+2; d<=n; d++){
						if(map[i][d]!=0) break;
						map[i][d] = map[i][d-1];
						map[i][d-1] = 0;
					}
					visit[i][d-1] = true;
				}
			}
		}
	}
	if(idx == LEFT){
		for(int i = 1;i<=n;i++){
			for(int j = 2 ;j<=n;j++){
				if (map[i][j] == 0) continue;
				int k;
				for(k = j-1; k>=1; k--){
					if(map[i][k]!=0) break;
					map[i][k] = map[i][k+1];
					map[i][k+1] = 0;
				}
				k++;
				if (map[i][k] == map[i][k-1] && visit[i][k-1] == false){
					map[i][k] = 0;
					map[i][k-1] *= 2;
					int d;
					for(d = k-2; d>=1; d--){
						if(map[i][d]!=0) break;
						map[i][d] = map[i][d+1];
						map[i][d+1] = 0;
					}
					visit[i][d+1] = true;
				}
			}
		}
	}
	if(idx == DOWN){
		for(int i = n-1;i>=1;i--){
			for(int j = 1;j<=n;j++){
				if (map[i][j] == 0) continue;
				int k;
				for(k = i+1; k<=n; k++){
					if(map[k][j]!=0) break;
					map[k][j] = map[k-1][j];
					map[k-1][j] = 0;
				}
				k--;
				if (map[k][j] == map[k+1][j] && visit[k+1][j] == false){
					map[k][j] = 0;
					map[k+1][j] *= 2;
					int d;
					for(d = k+2; d<=n; d++){
						if(map[d][j]!=0) break;
						map[d][j] = map[d-1][j];
						map[d-1][j] = 0;
					}
					visit[d-1][j] = true;
				}
			}
		}
	}
	if(idx == UP){
		for(int i = 2;i<=n;i++){
			for(int j = 1;j<=n;j++){
				if (map[i][j] == 0) continue;
				int k;
				for(k = i-1; k>=1; k--){
					if(map[k][j]!=0) break;
					map[k][j] = map[k+1][j];
					map[k+1][j] = 0;
				}
				k++;
				if (map[k][j] == map[k-1][j] && visit[k-1][j] == false){
					map[k][j] = 0;
					map[k-1][j] *= 2;
					int d;
					for(d = k-2; d>=1; d--){
						if(map[d][j]!=0) break;
						map[d][j] = map[d+1][j];
						map[d+1][j] = 0;
					}
					visit[d+1][j] = true;
				}
			}
		}
	}
	// if(cnt<=0){
	// 	cout<<idx<<'\t'<<cnt<<'\n';
	// 	for(int i = 1;i<=n;i++){
	// 		for(int j = 1;j<=n;j++){
	// 			cout<<map[i][j]<<'\t';
	// 		}
	// 		cout<<'\n';
	// 	}
	// 	cout<<endl;

	// }
	for(int i = 0;i<4;i++){
		int pre[23][23];
		memcpy(pre,map,sizeof(map));
		dfs(i,cnt + 1);
		memcpy(map,pre,sizeof(map));
	}
	
}

int main()
{
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> n;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			cin>>map[i][j];
		}
	}
	for(int i = 0;i<4;i++){
		int pre[23][23];
		memcpy(pre,map,sizeof(map));
		dfs(i,0);
		memcpy(map,pre,sizeof(map));
	}
	cout<<ans;
    return 0;
}
