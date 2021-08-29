#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int arr[20][20];
int n;
int ans = 0;
void pipe(int x1,int y1,int x2,int y2){
	if(x2==n && y2==n){
		ans+=1;
		return;
	}
	if(x2!=x1 && y1==y2){
		if(arr[y2][x2+1] == 0) pipe(x1+1,y1,x2+1,y2);
		if(arr[y2][x2+1] == 0 && arr[y2+1][x2] == 0 && arr[y2+1][x2+1] == 0 ) pipe(x1+1,y1,x2+1,y2+1);
	}
	if(x2==x1 && y1!=y2){
		if(arr[y2+1][x2] == 0) pipe(x1,y1+1,x2,y2+1);
		if(arr[y2+1][x2] == 0 && arr[y2][x2+1] == 0 && arr[y2+1][x2+1] == 0 ) pipe(x1,y1+1,x2+1,y2+1);
	}
	if(x2!=x1 && y1!=y2){
		if(arr[y2][x2+1] == 0) pipe(x1+1,y1+1,x2+1,y2);
		if(arr[y2+1][x2] == 0) pipe(x1+1,y1+1,x2,y2+1);
		if(arr[y2+1][x2] == 0 && arr[y2][x2+1] == 0 && arr[y2+1][x2+1] == 0 ) pipe(x1+1,y1+1,x2+1,y2+1);
	}
}

	
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	cin>>n;
	for(int i = 0;i<20;i++){
		for(int j = 0;j<20;j++){
			arr[i][j]=1;
		}
	}
	
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			cin>>arr[i][j];
		}
	}
	pipe(1,1,2,1);
	cout<<ans;
	return 0;
}
