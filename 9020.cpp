#include<iostream>
using namespace std;
int arr[10001];
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int t,n;
	arr[0]=arr[1]=1;
	for(int i = 2;i<=100;i++){
	    for(int j = i;i*j<=10000;j++){
	        arr[i*j]=1;
	    }
	}
	cin>>t;
	while(t--){
	    cin>>n;
	    for(int i = n/2;i>=2;i--){
	        if(arr[i]+arr[n-i] == 0){
	            cout<<i<<' '<<n-i<<'\n';
	            break;
	        }
	    }
	}
	
	
}
