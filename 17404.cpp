#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
	int n,_min=1e9;
	
	
	int arr[10001][3];
	int r[10001][3];
	int g[10001][3];
	int b[10001][3];
	cin>>n;
	cin>>arr[1][0]>>arr[1][1]>>arr[1][2]; // R G B
	
	r[1][1]=r[1][2]=1e9;
	g[1][0]=g[1][2]=1e9;
	b[1][0]=b[1][1]=1e9;
	
	r[1][0]=arr[1][0];
	g[1][1]=arr[1][1];
	b[1][2]=arr[1][2];
	
	for(int i = 2;i<=n;i++){
		cin>> arr[i][0] >> arr[i][1] >> arr[i][2];
		r[i][0]=arr[i][0] + min(r[i-1][1],r[i-1][2]);
		g[i][0]=arr[i][0] + min(g[i-1][1],g[i-1][2]);
		b[i][0]=arr[i][0] + min(b[i-1][1],b[i-1][2]);
		
		r[i][1]=arr[i][1] + min(r[i-1][0],r[i-1][2]);
		g[i][1]=arr[i][1] + min(g[i-1][0],g[i-1][2]);
		b[i][1]=arr[i][1] + min(b[i-1][0],b[i-1][2]);
		
		r[i][2]=arr[i][2] + min(r[i-1][0],r[i-1][1]);
		g[i][2]=arr[i][2] + min(g[i-1][0],g[i-1][1]);
		b[i][2]=arr[i][2] + min(b[i-1][0],b[i-1][1]);
	}
	_min = min(_min,min(r[n][1],r[n][2]));
	_min = min(_min,min(g[n][0],g[n][2]));
	_min = min(_min,min(b[n][1],b[n][0]));
	cout<<_min;
    return 0;
}
