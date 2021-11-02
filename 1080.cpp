#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int m1[51][51];
int m2[51][51];
int main()
{
	
	int n, m;
	
	scanf("%d %d",&n,&m);
	
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			scanf("%1d", &m1[i][j]);
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			scanf("%1d", &m2[i][j]);
		}
	}
	
	int cnt = 0;
	
	for(int i = 1;i<=n - 2;i++){
		for(int j = 1;j<=m - 2;j++){
			if(m1[i][j] != m2[i][j]){
				cnt++;
				for(int y = 0;y<3;y++){
					for(int x = 0;x<3;x++){
						m1[i+y][j+x] = (m1[i+y][j+x] ^ 1);
					}
				}
				
			}
		}
	}
	
	
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(m1[i][j] != m2[i][j]){
				printf("-1");
				return 0;
			}
		}
	}
	printf("%d",cnt);
	return 0;
	
}
