#include <iostream>
#include <algorithm>
using namespace std;

int arr[12][12];
int visit[12][12];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ans = -1e9;
int n, m, k;



void func(int cnt, int sum){
	if(cnt == k) {
		ans = max(sum, ans);
		return;
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(visit[i][j]) continue;
			visit[i][j]++;
			for(int l = 0;l<4;l++){
				int nx = j + dx[l];
				int ny = i + dy[l];
				
				visit[ny][nx]++;
			}
			func(cnt + 1, sum + arr[i][j]);
			
			for(int l = 0;l<4;l++){
				int nx = j + dx[l];
				int ny = i + dy[l];
				visit[ny][nx]--;
			}
			visit[i][j]--;
		}
	}
	
}

int main()
{
	
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	for(int i = 0;i<12;i++){
		for(int j = 0;j<12;j++) arr[i][j]= -1e9;
	}
	cin >> n >> m >> k;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			cin>>arr[i][j];
		}
	}
	
	func(0, 0);
	cout << ans;
	return 0;
	
}
