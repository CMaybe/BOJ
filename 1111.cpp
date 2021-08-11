#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int arr[1002];
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n;
	bool flag = true;
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>arr[i];
	}
	if(n==1) cout<<'A';
	else if(n==2){
		if(arr[0]==arr[1]) cout<<arr[0];
		else cout<<'A';
	}
	else{
		int a = 0;
		int b = 0;
		int dx=arr[1]-arr[0];
		int dy=arr[2]-arr[1];
		if(dx!=0) a=dy/dx;
		b=arr[1]-a*arr[0];
		for(int i = 1;i<n;i++){
			if(arr[i]!=(arr[i-1]*a+b)){
				flag = false;
				break;
			}
		}
		if(flag) cout<<(arr[n-1]*a+b);
		else cout<<'B';
	}
	return 0;
}
