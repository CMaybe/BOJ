#include<cstring>
#include<iostream>

using namespace std;
long long arr[1000001];
int main()
{
	int n, m,s = 0;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
	    memset(arr,0,sizeof(arr));
	    arr[0]=0;
	    arr[1]=1;
	    arr[2]=2;
	    arr[3]=4;
	    cin>>m;
	    for(int j =4;j<=m;j++){
	        arr[j]=(arr[j-3]+arr[j-2]+arr[j-1]) %1000000009;
	    }
        cout<<arr[m]<<'\n';
	}
}
