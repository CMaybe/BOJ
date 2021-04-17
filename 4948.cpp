#include<iostream>
using namespace std;
int arr[123456*2+1];
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n;
	arr[0]=arr[1]=1;
	for(int i = 2;i<=500;i++){
	    for(int j = i;i*j<=123456*2;j++){
	        arr[i*j]=1;
	    }
	}
	while(true){
	    int cnt = 0;
	    cin>>n;
	    if(n==0) break;
	    for(int i = n+1;i<=2*n;i++){
	        if(arr[i]==0){
	            cnt++;   
	        }
	    }
	    cout<<cnt<<'\n';
	}
	
	
}
