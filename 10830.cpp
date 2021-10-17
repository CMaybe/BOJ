#include <cstdio>

using namespace std;


int main() {
	
	int n;
	unsigned long long int b;
	int m[10][10];
	int ans[10][10] = {0,};
	
	scanf("%d %lld",&n, &b);
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			scanf("%d", &m[i][j]);
			if(i==j) ans[i][j]=1;
		}
	}
	while(b>0){
		if (b & 1){
			int temp[10][10] = {0,};
			for(int i = 1;i<=n;i++){
				for(int j = 1;j<=n;j++){
					temp[i][j]=0;
					for(int k = 1;k<=n;k++){
						temp[i][j] += ans[i][k] * m[k][j];
					}
				}
			}
			
			for(int i = 1;i<=n;i++){
				for(int j = 1;j<=n;j++){
					ans[i][j] = temp[i][j] % 1000;
				}
			}
		}
		
		int temp[10][10] = {0,};
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				temp[i][j]=0;
				for(int k = 1;k<=n;k++){
					temp[i][j] += m[i][k] * m[k][j];
				}
			}
		}
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				m[i][j] = temp[i][j] % 1000;
			}
		}	
		b/=2;
	}
	
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			printf("%d ",ans[i][j]);
		}
		printf("\n");
	}
	
}
