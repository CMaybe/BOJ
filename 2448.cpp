#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int arr[4000][8000];
int n = 0;
int ans = 0;
void star(int x,int y,int len){
	if(len <= 4){
		arr[y][x]=1;
		arr[y+1][x-1]=1;
		arr[y+1][x+1]=1;
		for(int i = -2;i<=2;i++) arr[y+2][x+i]=1;
		return;
	}
	star(x,y,len/2);
	star(x-len/2,y+len/2,len/2);
	star(x+len/2,y+len/2,len/2);
	
}

	
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	cin>>n;
	star(n,0,n);
	for(int i = 0;i<=n;i++){
		for(int j = 1; j<n*2;j++){
			if(arr[i][j]==0) cout<<' ';
			if(arr[i][j]==1) cout<<'*';
		}
		cout<<'\n';
	}
	return 0;
}
