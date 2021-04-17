#include<iostream>
using namespace std;
int arr[10001];
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int m,n;
	arr[0]=arr[1]=1;
	for(int i = 2;i<=100;i++){
	    for(int j = i;i*j<=10000;j++){
	        arr[i*j]=1;
	    }
	}
	cin>>m>>n;
	long long min=1e9,sum=0;
	for(int i = n;i>=m;i--){
	    if(arr[i]==0){
	        min=i;
	        sum+=i;
	    }
	}
	if(sum==0) cout<<-1;
	else cout<<sum<<'\n'<<min;
	
	
}
