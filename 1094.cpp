#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int arr[1000001];
int n;


int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	
	cin>>n;
	
	arr[0]=0;
	arr[1]=1;
	arr[2]=2;
	arr[3]=3;
	arr[4]=5;
	
	for(int i = 5;i<=n;i++){
	    arr[i]=(arr[i-1] + arr[i-2]) % 15746;
	}
	cout<<arr[n];
}
