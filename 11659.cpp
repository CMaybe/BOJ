#include<iostream>
using namespace std;

int arr[1000001];

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int m,n;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
	    cin>>arr[i];
	    arr[i]+=arr[i-1];
	}
	
	for(int i = 0;i<m;i++){
	    int a,b;
	    cin>>a>>b;
	    cout<<arr[b]-arr[a-1]<<'\n';
	}
	
}
