#include<cstdio>
#include<algorithm>
#include<queue>
#include<set>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

typedef struct DOMINO{
	int n;
	int m;
}Domino;


bool finish = false;


int arr[11][11];
bool cols[10][10];
bool rows[10][10];
bool block[4][4][10];
bool visit_domino[11][11];
int blank = 0;
int dominos_cnt = 0;

vector<Domino> dominos;


void dfs(int idx){
	if(finish) return;
	if(idx == dominos_cnt){
		finish = true;
		return;
	}
	int n = dominos[idx].n;
	int m = dominos[idx].m;
	for(int y = 1;y<=9;y++){
		for(int x = 1;x<=9;x++){
			if(arr[y][x] == 0){
				if(x!=9 && arr[y][x+1] == 0){
					if(cols[x][n] || rows[y][n] || block[(y-1)/3+1][(x-1)/3+1][n]) {}
					else if(cols[x+1][m] || rows[y][m] || block[(y-1)/3+1][x/3+1][m]) {}
					else{
						arr[y][x]=n;
						arr[y][x+1]=m;

						cols[x][n]=true;
						rows[y][n]=true;

						cols[x+1][m]=true;
						rows[y][m]=true;

						block[(y-1)/3+1][(x-1)/3+1][n]=true;
						block[(y-1)/3+1][(x)/3+1][m]=true;

						dfs(idx + 1);
						if(finish) return;        


						arr[y][x]=0;
						arr[y][x+1]=0;
						cols[x][n]=false;
						rows[y][n]=false;
						cols[x+1][m]=false;
						rows[y][m]=false;
						block[(y-1)/3+1][(x-1)/3+1][n]=false;
						block[(y-1)/3+1][(x)/3+1][m]=false;
					}
				}
				
				if(y!=9 && arr[y+1][x] == 0){
					if(cols[x][n] || rows[y][n] || block[(y-1)/3+1][(x-1)/3+1][n]) {}
					else if(cols[x][m] || rows[y+1][m] || block[y/3+1][(x-1)/3+1][m]) {}
					else{
						arr[y][x]=n;
						arr[y+1][x]=m;
						cols[x][n]=true;
						rows[y][n]=true;

						cols[x][m]=true;
						rows[y+1][m]=true;

						block[(y-1)/3+1][(x-1)/3+1][n]=true;
						block[(y)/3+1][(x-1)/3+1][m]=true;


						dfs(idx + 1);

						if(finish) return;        


						arr[y][x]=0;
						arr[y+1][x]=0;

						cols[x][n]=false;
						rows[y][n]=false;

						cols[x][m]=false;
						rows[y+1][m]=false;

						block[(y-1)/3+1][(x-1)/3+1][n]=false;
						block[(y)/3+1][(x-1)/3+1][m]=false;	
					}

				}
				
			}
		}
	}
	
	n = dominos[idx].m;
	m = dominos[idx].n;
	for(int y = 1;y<=9;y++){
		for(int x = 1;x<=9;x++){
			if(arr[y][x] == 0){
				if(x!=9 && arr[y][x+1] == 0){
					if(cols[x][n] || rows[y][n] || block[(y-1)/3+1][(x-1)/3+1][n]) {}
					else if(cols[x+1][m] || rows[y][m] || block[(y-1)/3+1][x/3+1][m]) {}
					else{
						arr[y][x]=n;
						arr[y][x+1]=m;

						cols[x][n]=true;
						rows[y][n]=true;

						cols[x+1][m]=true;
						rows[y][m]=true;

						block[(y-1)/3+1][(x-1)/3+1][n]=true;
						block[(y-1)/3+1][(x)/3+1][m]=true;
						dfs(idx + 1);

						if(finish) return;        


						arr[y][x]=0;
						arr[y][x+1]=0;
						cols[x][n]=false;
						rows[y][n]=false;
						cols[x+1][m]=false;
						rows[y][m]=false;
						block[(y-1)/3+1][(x-1)/3+1][n]=false;
						block[(y-1)/3+1][(x)/3+1][m]=false;
					}
					

					
				}
				
				if(y!=9 && arr[y+1][x] == 0){
					if(cols[x][n] || rows[y][n] || block[(y-1)/3+1][(x-1)/3+1][n]){}
					else if(cols[x][m] || rows[y+1][m] || block[y/3+1][(x-1)/3+1][m]){}
					else{
						arr[y][x]=n;
						arr[y+1][x]=m;
						cols[x][n]=true;
						rows[y][n]=true;

						cols[x][m]=true;
						rows[y+1][m]=true;

						block[(y-1)/3+1][(x-1)/3+1][n]=true;
						block[(y)/3+1][(x-1)/3+1][m]=true;

						dfs(idx + 1);

						if(finish) return;        


						arr[y][x]=0;
						arr[y+1][x]=0;

						cols[x][n]=false;
						rows[y][n]=false;

						cols[x][m]=false;
						rows[y+1][m]=false;

						block[(y-1)/3+1][(x-1)/3+1][n]=false;
						block[(y)/3+1][(x-1)/3+1][m]=false;
					}
					

				}
				
			}
		}
	}
	
}


int main()
{
	int n,m;
	
	scanf("%d",&n);
	int tc = 0;
	while(n!=0)
	{	
		dominos.clear();
		dominos_cnt = 0;
		finish = false;
		memset(arr,0,sizeof(arr));
		memset(cols,0,sizeof(cols));
		memset(rows,0,sizeof(rows));
		memset(block,0,sizeof(block));
		memset(visit_domino,false,sizeof(visit_domino));
		for(int i = 0;i<n;i++){
			int num1,num2;
			int x;
			char y;
			
			scanf("%d %1c%d ",&num1,&y,&x);
			arr[y-'A' + 1][x]=num1;
			
			scanf("%d %1c%1d",&num2,&y,&x);
			arr[y-'A' + 1][x]=num2;
			visit_domino[num1][num2] = true;
			visit_domino[num2][num1] = true;
		}
		for(int i = 1;i<=9;i++){
			int x;
			char y;
			scanf(" %1c%1d",&y,&x);
			arr[y-'A' + 1][x]=i;
			
		}
		for(int i = 1;i<=9;i++){
			for(int j = i+1;j<=9;j++){
				if(i==j) continue;
				if(visit_domino[i][j]){
					continue;
				}
				dominos.push_back({i,j});
				dominos_cnt++;
			}
		}

		
		for(int y = 1;y<=9;y++){
			for(int x = 1;x<=9;x++){
				if(arr[y][x]>0){
	            	cols[x][arr[y][x]]=true;
	            	rows[y][arr[y][x]]=true;
	            	block[(y-1)/3 + 1][(x-1)/3+1][arr[y][x]]=true;
	        	}
			}
		}
		dfs(0);
		tc++;
		printf("Puzzle %d\n",tc);
		for(int i = 1;i<=9;i++){
			for(int j = 1;j<=9;j++){
				printf("%d",arr[i][j]);
			}
			printf("\n");
		}
		
		scanf("%d",&n);
	}
	
}
